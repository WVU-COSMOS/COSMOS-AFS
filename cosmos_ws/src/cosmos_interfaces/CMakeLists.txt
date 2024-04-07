cmake_minimum_required(VERSION 3.8)
project(cosmos_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ReactionWheels.msg"
  "msg/Position.msg"
  "msg/Attitude.msg"
  "msg/StateMachine.msg"
  "msg/Camera.msg"
  "msg/DCM.msg"
  "srv/AAToDCM.srv"
  "srv/Skew.srv"
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
