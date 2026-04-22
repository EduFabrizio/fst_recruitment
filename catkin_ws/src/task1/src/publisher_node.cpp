#include <ros/ros.h> 
#include <std_msgs/Int32.h>
#include <iostream>

int main(int argc, char **argv){
    ros::init(argc, argv, "number_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("number", 10);
    ROS_INFO("Publisher node started, publishing to topic 'number' at 1 Hz");
    
    while (ros::ok())
    {
        std_msgs::Int32 msg;
        std::cout << "Digite um inteiro ou cntrl+c para sair: ";
        std::cin >> msg.data;
        pub.publish(msg);
        ROS_INFO("Publicado: %d", msg.data);
    }
    
    return 0;
}