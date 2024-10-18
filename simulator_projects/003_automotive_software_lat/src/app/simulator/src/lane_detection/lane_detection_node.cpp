/**
 * @copyright Hanyang University, Department of Automotive Engineering, 2024. All rights reserved. 
 *            Subject to limited distribution and restricted disclosure only.
 *            
 * @file      lane_detection_node.cpp
 * @brief     simulate lane detection
 * 
 * @date      2018-11-16 created by Eunsan Jo (eunsan.mountain@gmail.com)
 *            2023-08-07 updated by Yuseung Na (yuseungna@hanyang.ac.kr)
 *              : adapt new template
 *            2023-08-20 updated by Yuseung Na (yuseungna@hanyang.ac.kr)
 *              : change to ROS2
 */

#include "lane_detection/lane_detection_node.hpp"

LaneDetection::LaneDetection(const std::string& node_name, const double& loop_rate,
                                     const rclcpp::NodeOptions& options)
    : Node(node_name, options) {
    
    RCLCPP_WARN(this->get_logger(), "Initialize node...");
    
    // QoS init
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    // Parameters
    this->declare_parameter("lane_detection/ROIFront", 20.0);
    if (!this->get_parameter("lane_detection/ROIFront", param_.m_ROIFront_param)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to get ROIFront");
    }
    else {
        RCLCPP_INFO(this->get_logger(), "ROIFront: %f", param_.m_ROIFront_param);
    }
    this->declare_parameter("lane_detection/ROIRear", 10.0);
    if (!this->get_parameter("lane_detection/ROIRear", param_.m_ROIRear_param)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to get ROIRear");
    }
    else {
        RCLCPP_INFO(this->get_logger(), "ROIRear: %f", param_.m_ROIRear_param);
    }
    this->declare_parameter("lane_detection/ROILeft", 3.0);
    if (!this->get_parameter("lane_detection/ROILeft", param_.m_ROILeft_param)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to get ROILeft");
    }
    else {
        RCLCPP_INFO(this->get_logger(), "ROILeft: %f", param_.m_ROILeft_param);
    }
    this->declare_parameter("lane_detection/ROIRight", 3.0);
    if (!this->get_parameter("lane_detection/ROIRight", param_.m_ROIRight_param)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to get ROIRight");
    }
    else {
        RCLCPP_INFO(this->get_logger(), "ROIRight: %f", param_.m_ROIRight_param);
    }
    this->declare_parameter("lane_detection/ns", "");
    if (!this->get_parameter("lane_detection/ns", param_.vehicle_namespace)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to get vehicle_namespace");
    }
    else {
        RCLCPP_INFO(this->get_logger(), "vehicle_namespace: %s", param_.vehicle_namespace.c_str());
    }    
    
    std::string dir(getenv("PWD"));
    std::string csv_path("/resources/csv/simulation_lane");
    param_.ref_csv_path = dir + csv_path;
    RCLCPP_INFO(this->get_logger(), "ref_csv_path: %s", param_.ref_csv_path.c_str());

    // Subscribers
    s_vehicle_state_ = this->create_subscription<ad_msgs::msg::VehicleOutput> (
        "vehicle_state", qos_profile, std::bind(&LaneDetection::CallbackVehicleState, this, std::placeholders::_1));

    // Publishers
    p_csv_lanes_ = this->create_publisher<ad_msgs::msg::LanePointDataArray>(
        "csv_lanes", qos_profile);
    p_roi_lanes_ = this->create_publisher<ad_msgs::msg::LanePointDataArray>(
        "ROI_lanes", qos_profile);
    p_lane_points_array_ = this->create_publisher<ad_msgs::msg::LanePointDataArray>(
        "lane_points_array", qos_profile);

    // Initialize
    Init(this->now());

    // Timer init
    t_run_node_ = this->create_wall_timer(
        std::chrono::milliseconds((int64_t)(1000 / loop_rate)),
        [this]() { this->Run(this->now()); }); 
}

LaneDetection::~LaneDetection() {}

void LaneDetection::Init(const rclcpp::Time& current_time) {    

    // Algorithm
    time_prev_csv_lanes_ = 0.0;
    ptr_lane_detection_algorithm_ = std::make_unique<LaneDetectionAlgorithm>(param_);
    i_csv_lanes_ = ptr_lane_detection_algorithm_->LoadLanesData();
}

void LaneDetection::Run(const rclcpp::Time& current_time) {
    if (param_is_simulator_on_ == false) {
        return;
    }
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    // Get subscribe variables
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    mutex_vehicle_state_.lock();
    interface::VehicleState vehicle_state = i_vehicle_state_;
    mutex_vehicle_state_.unlock();
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    // Algorithm
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //  

    // Extract lanes in ROI
    interface::Lanes roi_lanes = ptr_lane_detection_algorithm_->ExtractROI(vehicle_state);

    // Find ROI Points
    FindROIPoints(roi_lanes);
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    // Update output
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    UpdateLanePointData(roi_lanes);
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    // Publish output
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    Publish(current_time);
}

void LaneDetection::Publish(const rclcpp::Time& current_time) {
    if (param_is_simulator_on_ == false) {
        return;
    }

    if ((current_time.seconds() - time_prev_csv_lanes_) > 5.0) {
        time_prev_csv_lanes_ = current_time.seconds();
        p_csv_lanes_->publish(o_csv_lanes_); 
    }

    p_roi_lanes_->publish(o_roi_lanes_);
    p_lane_points_array_->publish(o_lane_points_array_);
}

/**
 * brief: Select points in ROI.
 * input: roi_lanes
 * output: o_lanes_points_array_
 */
void LaneDetection::FindROIPoints(const interface::Lanes& roi_lanes) {
    ad_msgs::msg::LanePointDataArray lane_points_array;
    lane_points_array.frame_id = param_.vehicle_namespace + "/body";
    lane_points_array.id = roi_lanes.id; // "unknown";
    for (const auto& roi_lane : roi_lanes.lane) {
        ad_msgs::msg::LanePointData lane_points;
        lane_points.frame_id = param_.vehicle_namespace + "/body";
        lane_points.id = roi_lane.id; // "unknown";
        for (const auto& point : roi_lane.point) {
            geometry_msgs::msg::Point lanepoints;
            lanepoints.x = point.x;
            lanepoints.y = point.y;
            lane_points.point.push_back(lanepoints);
        }
        lane_points_array.lane.push_back(lane_points);
    }
    o_lane_points_array_ = lane_points_array;
}

void LaneDetection::UpdateLanePointData(const interface::Lanes& roi_lanes) {
    o_csv_lanes_.frame_id = i_csv_lanes_.frame_id;
    o_csv_lanes_.id = i_csv_lanes_.id;
    o_csv_lanes_.lane.clear();
    ad_msgs::msg::LanePointDataArray csv_lanes;
    ad_msgs::msg::LanePointDataArray o_roi_lanes;

    for (const auto& csv_lane : i_csv_lanes_.lane) {
        ad_msgs::msg::LanePointData lane;
        lane.frame_id = csv_lane.frame_id;
        lane.id = csv_lane.id;

        for (const auto& csv_point : csv_lane.point) {
            geometry_msgs::msg::PointStamped lanePoint_world;
            lanePoint_world.point.x = csv_point.x;
            lanePoint_world.point.y = csv_point.y;
            
            lane.point.push_back(lanePoint_world.point);
        }
        csv_lanes.lane.push_back(lane);
    }
    o_csv_lanes_ = csv_lanes;

    o_roi_lanes_.frame_id = roi_lanes.frame_id;
    o_roi_lanes_.id = roi_lanes.id;

    for (const auto& roi_lane : roi_lanes.lane) {
        ad_msgs::msg::LanePointData lane;
        lane.frame_id = roi_lane.frame_id;
        lane.id = roi_lane.id;

        for (const auto& roi_point : roi_lane.point) {
            geometry_msgs::msg::PointStamped lanePoint_world;
            lanePoint_world.point.x = roi_point.x;
            lanePoint_world.point.y = roi_point.y;
            
            lane.point.push_back(lanePoint_world.point);
        }
        o_roi_lanes.lane.push_back(lane);
    }
    o_roi_lanes_ = o_roi_lanes;
}

int main(int argc, char **argv) {
    std::string node_name = "lane_detection";
    double loop_rate      = 30.0;

    // Initialize node
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LaneDetection>(node_name, loop_rate));
    rclcpp::shutdown();

    return 0;
}
