#include <algorithm>
#include <ctime>
#include <iostream>

#include "neuron.h"

neuron::neuron(int num_inputs) : weights_from_input(std::vector<float>(num_inputs)){
    std::srand(std::time(0)); // use current time as seed for random generator

    // Initialize all input weights to random values in the interval [-0.5, 0,5]
    std::transform(weights_from_input.begin(), weights_from_input.end(), weights_from_input.begin(), [](float weight){
        return (((float)rand()) / (float)RAND_MAX) - 0.5f;
    });
}

void neuron::print_weights(){

    for_each(weights_from_input.begin(), weights_from_input.end(), [](float weight){
        std::cout << weight << std::endl;
    });
}