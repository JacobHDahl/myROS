#include <iostream>
#include "ros/ros.h"
#include <std_msgs/Int16.h>

void chatterCallback(const std_msgs::Int16::ConstPtr& msg){
    ROS_INFO("I heard: [%i]", msg->data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "random_listener");

    ros::NodeHandle nh;

    ros::Subscriber random_sub = nh.subscribe("random_topic",10,chatterCallback);

    ros::spin();

    return 0;
}
