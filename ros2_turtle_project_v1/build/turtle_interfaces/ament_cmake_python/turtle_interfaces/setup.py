from setuptools import find_packages
from setuptools import setup

setup(
    name='turtle_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('turtle_interfaces', 'turtle_interfaces.*')),
)
