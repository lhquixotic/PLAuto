import os
import math
import json

import ros_compatibility as roscomp
from ros_compatibility.exceptions import *
from ros_compatibility.node import CompatibleNode

from carla_msgs.msg import CarlaActorList
from carla_msgs.srv import SpawnObject, DestroyObject
from diagnostic_msgs.msg import KeyValue
from geometry_msgs.msg import Pose

# ==============================================================================
# -- CarlaScenarioGeneration() --------------------------------------------------------------------
# ==============================================================================

class CarlaScenarioGeneration(CompatibleNode):
    """
    Handles the spawning of the ego vehicle, its sensors and the platoon vehicle
    """
    def __init__(self):
        super(CarlaScenarioGeneration).__init__('carla_scenario_generation')

        self.objects_definition_file = self.get_param('object_definition_file','')
        self.spawn_sensors_only = self.get_param('s')




# ==============================================================================
# -- main() --------------------------------------------------------------------
# ==============================================================================


def main(args=None):
    """
    main function
    """
    roscomp.init("senario_generation", args=args)
    scenario_generation_node = None
    try:
        scenario_generation_node = CarlaScenarioGeneration()
        roscomp.on_shutdown(scenario_generation_node.destroy)
    except KeyboardInterrupt:
        roscomp.logerr("Could not initialize CarlaScenarioGeneration. Shutting down.")

    if scenario_generation_node:
        try:
            scenario_generation_node.spawn_objects() # TODO
            try:
                scenario_generation_node.spin()
            except (ROSInterruptException, ServiceException, KeyboardInterrupt):
                pass
        except (ROSInterruptException, ServiceException, KeyboardInterrupt):
            scenario_generation_node.logwarn(
                "Spawning process has been interrupted. There might be actors that have not been destroyed properly")
        except RuntimeError as e:
            roscomp.logfatal("Exception caught: {}".format(e))
        finally:
            roscomp.shutdown()


if __name__ == '__main__':
    main()