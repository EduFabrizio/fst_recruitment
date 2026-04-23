#include <ros/ros.h> 
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point.h>
#include <iostream>

class NodePublicador{
private:
    ros::NodeHandle nh_;
public:
    NodePublicador(ros::NodeHandle* nh){ //construtorzinho
        nh_ = *nh;
        ROS_INFO("Classe do Publisher iniciada!");
    }

};
int main(int argc, char **argv){
    ros::init(argc, argv, "number_publisher2");
    ros::NodeHandle nh;
    
    NodePublicador o_publicador(&nh);
    ros::spin();
    
    return 0;
}