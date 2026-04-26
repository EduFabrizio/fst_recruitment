#include "task3/gerador_markers.hpp"
#include <ros/ros.h> // Apenas para usar o ros::Time::now() nos marcadores

MarkerGenerator::MarkerGenerator() {}

visualization_msgs::MarkerArray MarkerGenerator::getOutput() {
    return _output;
}

void MarkerGenerator::setInput(const task2::coords_2d_array& inputData) {
    _input = inputData;
}

void MarkerGenerator::runAlgorithm() {
    visualization_msgs::MarkerArray array_marcadores;

    // Copiamos a mesma logica de geracao de esferas da task 2 para isso
    for (size_t i = 0; i < _input.coordinates.size(); i++) {
        visualization_msgs::Marker marcador;
        marcador.header.frame_id = "map";
        marcador.header.stamp = ros::Time::now();
        marcador.ns = "fst_pontos";
        marcador.id = i;
        marcador.type = visualization_msgs::Marker::SPHERE;
        marcador.action = visualization_msgs::Marker::ADD;

        marcador.pose.position.x = _input.coordinates[i].x;
        marcador.pose.position.y = _input.coordinates[i].y;
        marcador.pose.position.z = 0.0;
        marcador.pose.orientation.w = 1.0;

        marcador.scale.x = 15.0; marcador.scale.y = 15.0; marcador.scale.z = 15.0;
        marcador.color.r = 0.0f; marcador.color.g = 0.5f; marcador.color.b = 1.0f; marcador.color.a = 1.0f;

        array_marcadores.markers.push_back(marcador);
    }
    
    _output = array_marcadores; // Salva o resultado
}