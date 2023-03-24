# PLAuto
This is an autonomous driving framework for both single vehicle and platoon based on ROS1. It can be implemented both on real-world vehicle and in simulation. Main code is written by C++ and partially by Python.
## Environments
 1. Ubuntu 20.04 + ROS Noetic

## Usage
### Preparations
Before complied with `catkin_make`, some packages are supposed to be installed 

``
sudo apt-get install ros-noetic-nmea-msgs ros-noetic-ackermann-msgs ros-noetic-derived-object-msgs ros-noetic-jsk-rviz-plugins ros-noetic-serial
``

### Real-world car

### Simulation
For simulation in the `CARLA simulator` (0.9.11 used in the code), you should first start the simulator and then launch the bridge by 

``
roslaunch launch/start_carla_simulation_scenario.launch
``

The initial scenario can be designed and modified in `/src/drivers/simulators/carla/carla_adapter/src/scenario_generation`.


### Status
[2023-03-24] The carla-ros bridge is ok, and control of the ego vehicle is to be done.

[2023-03-09] Main code is complied pass. The perception module is not complied at now.