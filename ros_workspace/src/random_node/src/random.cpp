#include <iostream>
#include <ros/ros.h>
#include <cstdlib>


int randomNum(int max){
    return rand()%(max+1);
}

int main(int argc, char **argv){
    
    srand (time(NULL));

    ros::init(argc,argv,"random");

    ros::NodeHandle n;






}





