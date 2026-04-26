#include "task3/marker_handle.hpp"

MarkerHandle::MarkerHandle(ros::NodeHandle &nodeHandle) : _nodeHandle(nodeHandle) {
    _pubOutput = _nodeHandle.advertise<visualization_msgs::MarkerArray>("marcadores_task3", 10);
    _subInput = _nodeHandle.subscribe("coordenadas", 10, &MarkerHandle::inputCallback, this);
}

void MarkerHandle::inputCallback(const task2::coords_2d_array::ConstPtr &input) {
    _generator.setInput(*input); // Passa o que o ROS ouviu pro Cérebro
}

void MarkerHandle::run() {
    _generator.runAlgorithm(); // Manda o Cérebro processar as esferas
    _pubOutput.publish(_generator.getOutput()); // Publica as esferas no ROS
}