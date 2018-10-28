#include <iostream>
#include "ros/ros.h"
#include <std_msgs/Int16.h>


void printerCallback(const std_msgs::Int16::ConstPtr &msg){
    ROS_INFO("The sum of the numbers is [%i]",msg->data);
}

int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "adder_listener");

    ros::NodeHandle nh;

    ros::Subscriber adder_sub = nh.subscribe("adder_topic" ,1 ,&printerCallback);

    ROS_INFO("INITIALIZED");

    ros::spin();


    return 0;
}
