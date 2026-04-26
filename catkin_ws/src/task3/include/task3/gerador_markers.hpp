#ifndef GERADOR_MARKERS_HPP
#define GERADOR_MARKERS_HPP

#include <task2/coords_2d_array.h>
#include <visualization_msgs/MarkerArray.h>

class MarkerGenerator {
public:
    MarkerGenerator(); // Construtor

    // Getters e Setters
    visualization_msgs::MarkerArray getOutput();
    void setInput(const task2::coords_2d_array& inputData);
    
    // Método principal
    void runAlgorithm();

private:
    task2::coords_2d_array _input;
    visualization_msgs::MarkerArray _output;
};

#endif