#include <ros/ros.h> 
#include <std_msgs/Int32.h>
#include <task2/coords_2d.h>
#include <task2/coords_2d_array.h>
#include <iostream>

class NodePublicador{
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_coordenadas;
    task2::coords_2d_array coordenadas;
public:
    NodePublicador(ros::NodeHandle* nh){ //construtorzinho
        nh_ = *nh;
        pub_coordenadas = nh_.advertise<task2::coords_2d_array>("coordenadas", 10);
        carregarParametros();
        ROS_INFO("Classe do Publisher iniciada!");
    }
    void carregarParametros(){
      XmlRpc::XmlRpcValue lista; //para ler yaml, tem que ser XmlRpcValue
        if (nh_.getParam("points", lista)) { //condiçao vai atras da lista "points"
        for(int i=0; i < lista.size(); i++) {
            XmlRpc::XmlRpcValue ponto = lista[i]; //cada ponto é um XmlRpcValue
            task2::coords_2d ponto_msg; //cria a mensagem do tipo coords_2d
            ponto_msg.x = static_cast<float>(static_cast<int>(ponto[0])); //atribui o valor de x do ponto à mensagem
            ponto_msg.y = static_cast<float>(static_cast<int>(ponto[1])); //atribui o valor de y do ponto à mensagem
            coordenadas.coordinates.push_back(ponto_msg); //adicion
        }
        ROS_INFO("Coordenadas carregadas com sucesso!");
    }}
    void publicaCiclicamente(){
        ros::Rate loop_rate(1); //publica a cada 1 segundo
        while (ros::ok()) {
            pub_coordenadas.publish(coordenadas); //publica a mensagem com as coordenadas
            ROS_INFO("%d Coordenadas publicadas!", static_cast<int>(coordenadas.coordinates.size()));
            ros::spinOnce();
            loop_rate.sleep();
    }}
};
int main(int argc, char **argv){
    ros::init(argc, argv, "number_publisher2");
    ros::NodeHandle nh;
    
    NodePublicador o_publicador(&nh);
    o_publicador.publicaCiclicamente();
    return 0;
}