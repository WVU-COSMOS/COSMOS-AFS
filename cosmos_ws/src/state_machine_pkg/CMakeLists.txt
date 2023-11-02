cmake_minimum_required(VERSION 3.8)
project(state_machine_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(state_machine src/state_machine_node.cpp)
ament_target_dependencies(state_machine rclcpp)

install(TARGETS
  state_machine
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
