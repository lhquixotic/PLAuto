cmake_minimum_required(VERSION 2.8.3)
project(sendprotocol)

add_compile_options(-std=c++11)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
# Each node in the package must be declared like this
add_library(${PROJECT_NAME}
   ${DIR_SRCS}
  )
