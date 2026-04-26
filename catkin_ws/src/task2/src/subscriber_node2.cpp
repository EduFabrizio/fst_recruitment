#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <task2/coords_2d.h>
#include <task2/coords_2d_array.h>

class NodeMarcadores {
private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_coordenadas;
    ros::Publisher pub_marcadores;

public:
    NodeMarcadores(ros::NodeHandle* nh) {
        nh_ = *nh;

        pub_marcadores = nh_.advertise<visualization_msgs::MarkerArray>("marcadores", 10);
        sub_coordenadas = nh_.subscribe("coordenadas", 10, &NodeMarcadores::callbackCoordenadas, this);
        ROS_INFO("Classe do Subscriber/Marcadores iniciada!");
    }

    void callbackCoordenadas(const task2::coords_2d_array::ConstPtr& msg) {
        
        visualization_msgs::MarkerArray array_marcadores; // A "caixa" que vai pro RViz

        // Um loop para transformar cada coords_2d em uma Esfera 3D
        for (size_t i = 0; i < msg->coordinates.size(); i++) {
            
            visualization_msgs::Marker marcador;
            
            // Configs para o RViz
            marcador.header.frame_id = "map";  // O nome do nosso 3D
            marcador.header.stamp = ros::Time::now();
            marcador.ns = "fst_pontos";        // Um nome/namespace
            marcador.id = i;                   // ID único usando o 'i' do loop (0 a 102)
            
            // Tipo e Ação
            marcador.type = visualization_msgs::Marker::SPHERE; // ESFERAS
            marcador.action = visualization_msgs::Marker::ADD;  // ADICIONAMOS

            // Posição no mundo (Copiamos da SUA mensagem customizada)
            marcador.pose.position.x = msg->coordinates[i].x;
            marcador.pose.position.y = msg->coordinates[i].y;
            marcador.pose.position.z = 0.0; // Pontos 2D, então coloquei Z sempre a zero
            
            marcador.pose.orientation.w = 1.0; // Rotação padrão (n sei se é necessario)

            // Escala (Como as coordenadas sao mtas tamanho 15 fica visível)
            marcador.scale.x = 15.0;
            marcador.scale.y = 15.0;
            marcador.scale.z = 15.0;

            // Cor RGBA (Red, Green, Blue, Alpha) - esferas Azuis!
            marcador.color.r = 0.0f;
            marcador.color.g = 0.5f;
            marcador.color.b = 1.0f;
            marcador.color.a = 1.0f; // Alpha = 1.0 significa 100% opaco

            // Esfera pronta dentro da caixa
            array_marcadores.markers.push_back(marcador);
        }

        // Publica a caixa para o RViz
        pub_marcadores.publish(array_marcadores);
    }

}; 

int main(int argc, char **argv) {
    ros::init(argc, argv, "node_marcadores_sub");
    ros::NodeHandle nh;

    
    NodeMarcadores meu_inscrito(&nh);

    
    ros::spin();

    return 0;
}