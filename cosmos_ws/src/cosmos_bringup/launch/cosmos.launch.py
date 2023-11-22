from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    state_machine_node = Node(
        package="state_machine_pkg",
        executable="state_machine"
    )

    gstation_node = Node(
        package="communication_pkg",
        executable="SerialCommunication"
    )

    attitude_node = Node(
        package="attitude_control_pkg",
        executable="attitude_control"
    )

    ld.add_action(state_machine_node)
    ld.add_action(gstation_node)
    ld.add_action(attitude_node)

    return ld