# pragma once

#define REGISTER_TOPIC_NAME_LOAD(config_name, topic, default_name)            \
if (!nodeHandle_.param<std::string>(config_name,                              \
                                      topic,                                  \
                                      default_name)) {                        \
    ROS_WARN_STREAM(std::string("Did not load") +                             \
                    config_name + std::string(". Standard value is: ")        \
                        << topic);                                            \
  }
