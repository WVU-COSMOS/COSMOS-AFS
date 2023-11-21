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
        executable="Ground_Station"
    )

    ld.add_action(state_machine_node)
    ld.add_action(gstation_node)

    return ld