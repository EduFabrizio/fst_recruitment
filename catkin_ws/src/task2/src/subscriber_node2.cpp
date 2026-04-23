#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <visualization_msgs/Marker.h>

class NodeMarcadores {
private:
    ros::NodeHandle nh_;

public:
    NodeMarcadores(ros::NodeHandle* nh) {
        nh_ = *nh;
        ROS_INFO("Classe do Subscriber/Marcadores iniciada!");
    }
}; 

int main(int argc, char **argv) {
    ros::init(argc, argv, "node_marcadores_sub");
    ros::NodeHandle nh;

    
    NodeMarcadores meu_inscrito(&nh);

    
    ros::spin();

    return 0;
}