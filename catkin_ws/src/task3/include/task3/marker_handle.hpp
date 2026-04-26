#ifndef MARKER_HANDLE_HPP
#define MARKER_HANDLE_HPP
#include "ros/ros.h"
// Inclui a classe do algoritmo de conversão (criada no arquivo anterior)
#include "task3/gerador_markers.hpp"

// Classe responsável por gerenciar a comunicação com o ROS (publicar e se inscrever em tópicos)
class MarkerHandle {
public:
    // Construtor que recebe o (NodeHandle)
    MarkerHandle(ros::NodeHandle &nodeHandle);
    
    // Método que mantém o nó rodando (loop principal)
    void run();

private:
    ros::NodeHandle _nodeHandle; 
    
    ros::Publisher _pubOutput;   // Publicador (envia os marcadores para o RViz)
    ros::Subscriber _subInput;   // Inscrito (recebe as coordenadas do task2)
    
    MarkerGenerator _generator;  // Instância do nosso algoritmo de conversão

    // Função de callback: ativada automaticamente sempre que uma nova mensagem de coordenadas chega
    void inputCallback(const task2::coords_2d_array::ConstPtr &input);
};

#endif