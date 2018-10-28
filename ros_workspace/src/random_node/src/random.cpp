#include <iostream>
#include <ros/ros.h>
#include <cstdlib>
#include <random_node/Num.h>
#include "std_msgs/Int16.h"

int randNum(int min, int max)
{
    return rand() % max + min;
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    ros::init(argc, argv, "random_talker");

    ros::NodeHandle nh;

    ros::Publisher random_pub = nh.advertise<random_node::Num>("random_topic", 10);

    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {

        random_node::Num random_number;

        random_number.num1 = randNum(0, 100);
        random_number.num2 = randNum(0, 100);

        ROS_INFO("%i", random_number.num1);
        ROS_INFO("ANDRE TALLET: [%i]", random_number.num2);

        random_pub.publish(random_number);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}
