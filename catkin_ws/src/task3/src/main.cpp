#include "ros/ros.h"
#include "task3/marker_handle.hpp"

int main(int argc, char** argv) {
    ros::init(argc, argv, "node_task3");
    ros::NodeHandle nh;

    MarkerHandle meuHandle(nh);
    ros::Rate loop_rate(10); // Roda o processamento a 10 Hz

    while (ros::ok()) {
        meuHandle.run();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}