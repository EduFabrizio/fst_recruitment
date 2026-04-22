#include <ros/ros.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber_node");
    ros::NodeHandle nh;
    ROS_INFO("Subscriber node started");
    ros::spin();
    return 0;
}
