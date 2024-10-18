#!/bin/zsh

# Set the path to your ROS2 workspace
ROS2_WS="$HOME/Programming/ROS2/automotive_software_simulator"

# Function to run a command in a tmux pane
run_in_pane() {
    tmux split-window -v
    tmux send-keys "$1" C-m
}

# Function to source workspace and run command
source_and_run() {
    echo "source ~/.zshrc && \
    source $ROS2_WS/install/setup.zsh && \
    cd $ROS2_WS && \
    $1"
}

# Run the simulator in the current pane
tmux send-keys "$(source_and_run "ros2 launch simulator simulation.launch.xml")" C-m

# Wait for 7 seconds
sleep 7

# Run the evaluation in a new pane
run_in_pane "$(source_and_run "ros2 launch evaluation evaluation.launch.xml")"

# Commented out section
# sleep 3
# run_in_pane "$(source_and_run "ros2 launch final_simulator simulation.launch")"

# Adjust the layout to make all panes equal size
tmux select-layout even-vertical
