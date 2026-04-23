#include <ros/ros.h> 
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point.h>
#include <iostream>

class NodePublicador{
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_coordenadas;
public:
    NodePublicador(ros::NodeHandle* nh){ //construtorzinho
        nh_ = *nh;
        pub_coordenadas = nh_.advertise<geometry_msgs::Point>("coordenadas", 10);
        ROS_INFO("Classe do Publisher iniciada!");
    }
    void publicaCiclicamente(){
        ros::Rate loop_rate(1); // 1 Hz
        while (ros::ok()){
            geometry_msgs::Point ponto;
            ponto.x = 2.6;
            ponto.y = 3.4;
            pub_coordenadas.publish(ponto);
            ROS_INFO("Publicado: (%.2f, %.2f)", ponto.x, ponto.y);
            ros::spinOnce();
            loop_rate.sleep();
        }
    }
};
int main(int argc, char **argv){
    ros::init(argc, argv, "number_publisher2");
    ros::NodeHandle nh;
    
    NodePublicador o_publicador(&nh);
    o_publicador.publicaCiclicamente();
    return 0;
}