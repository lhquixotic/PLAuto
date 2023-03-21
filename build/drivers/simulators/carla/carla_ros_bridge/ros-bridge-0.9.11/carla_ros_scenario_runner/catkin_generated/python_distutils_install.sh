#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/user/code/PLAuto/src/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_scenario_runner"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/user/code/PLAuto/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/user/code/PLAuto/install/lib/python3/dist-packages:/home/user/code/PLAuto/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/user/code/PLAuto/build" \
    "/usr/bin/python3" \
    "/home/user/code/PLAuto/src/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_scenario_runner/setup.py" \
     \
    build --build-base "/home/user/code/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_scenario_runner" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/user/code/PLAuto/install" --install-scripts="/home/user/code/PLAuto/install/bin"
