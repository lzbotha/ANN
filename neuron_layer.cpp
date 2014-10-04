#include <algorithm>

#include "neuron_layer.h"

neuron_layer::neuron_layer(int size_of_layer, int size_of_prev_layer){
    // Initialize size_of_layer neurons, this cannot be done in an initializer list as random values are assigned to variables
    for(int i = 0; i < size_of_layer; ++i){
        neurons.push_back(neuron(size_of_prev_layer));
    }
}

std::string neuron_layer::to_string(void){
    std::string temp;
    std::for_each(neurons.begin(), neurons.end(), [& temp](neuron & n){
        temp += n.to_string() + "\n\n";
    });

    return std::move(temp);
}