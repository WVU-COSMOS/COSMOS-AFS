cmake_minimum_required(VERSION 3.8)
project(attitude_control_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cosmos_interfaces REQUIRED)

include_directories(include)

add_executable(reaction_wheels src/reaction_wheels_node.cpp)
ament_target_dependencies(reaction_wheels rclcpp std_msgs cosmos_interfaces)

install(TARGETS
  reaction_wheels
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  include/
  DESTINATION include/${PROJECT_NAME}
)


ament_package()
