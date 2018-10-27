#include <iostream>
#include <ros/ros.h>
#include <cstdlib>
#include "std_msgs/Int16.h"

int randNum(int min, int max){
    return rand() % max + min;
}


int main(int argc, char **argv)
{
    srand(time(NULL));

    ros::init(argc,argv,"random_talker");
    
    ros::NodeHandle nh;

    ros::Publisher random_pub=nh.advertise<std_msgs::Int16>("random_topic",10);

    ros::Rate loop_rate(10);

    int count=0;
    while(ros::ok()){

        std_msgs::Int16 random_number;

        random_number.data=randNum(0,100);

        ROS_INFO("%i", random_number.data);

        random_pub.publish(random_number);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
        

    }

    return 0;
}
