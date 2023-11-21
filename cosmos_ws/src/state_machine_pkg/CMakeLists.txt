cmake_minimum_required(VERSION 3.8)
project(state_machine_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cosmos_interfaces REQUIRED)

include_directories(include)

add_executable(state_machine src/state_machine_node.cpp)
ament_target_dependencies(state_machine rclcpp std_msgs cosmos_interfaces)

install(TARGETS
  state_machine
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  include/
  DESTINATION include/${PROJECT_NAME}
)

ament_package()
