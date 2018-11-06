#include <iostream>
#include "ros/ros.h"
#include <random_node/Num.h>
#include <std_msgs/Int16.h>

/*The way to publish and subscribe in the same node is to make a class 
with the nodehandle, publisher and subscriber as members of the class.
Then in the constructor initialize the subscriber(s) and publisher(s).
The subscriber needs 2 extra arguments: The adress of the callback function 
and a pointer to its object(which is a this pointer). Then, in the callback
function you do the operations you need and publish the message(s). */

class Adder
{
  public:
    /**
     * Constructor without parameters is used for.... 
     */
    Adder()
    {
        random_sub_ = nh_.subscribe("random_topic", 1, &Adder::randomCallback, this);
        adder_pub_ = nh_.advertise<std_msgs::Int16>("adder_topic", 1);
    }

  private:
    ros::NodeHandle nh_;
    ros::Subscriber random_sub_;
    ros::Publisher adder_pub_;

    /**
     * Hva den gjør
     * 
     * param msg Message blir henta fra subscirptio
     * 
     */
    void randomCallback(const random_node::Num::ConstPtr &msg)
    {

        //increase the number with 32, because why not
        int first_number = msg->num1;
        int second_number = msg->num2;

        std_msgs::Int16 new_msg;
        new_msg.data = first_number + second_number;

        //publish new message
        adder_pub_.publish(new_msg);

        //print the new message
        ROS_INFO("I PUBLISH: [%i]", new_msg.data);
    }
};

int main(int argc, char **argv)
{
    //Initalize ROS node
    ros::init(argc, argv, "random_listener");

    //Make an object to start the constructor and then the callback function
    Adder adder;

    ROS_INFO("INITIALIZED");

    //This thingy
    ros::spin();

    //Because
    return 0;
}
