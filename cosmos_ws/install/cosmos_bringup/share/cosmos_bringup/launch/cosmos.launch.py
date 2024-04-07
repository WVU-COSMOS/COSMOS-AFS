from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    state_machine_node = Node(
        package="state_machine_pkg",
        executable="state_machine"
    )

    cam_state_machine_node = Node(
        package="camera_pkg",
        executable="CameraSM"
    )

    get_image_node = Node(
        package="camera_pkg",
        executable="GetImage"
    )

    image_to_pixel_node = Node(
        package="camera_pkg",
        executable="ImageToPixel"
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
    ld.add_action(cam_state_machine_node)
    ld.add_action(get_image_node)
    ld.add_action(image_to_pixel_node)
    ld.add_action(gstation_node)
    ld.add_action(attitude_node)

    return ld