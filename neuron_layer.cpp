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

void neuron_layer::feed_forward_from(const neuron_layer & prev_layer){
    // for each neuron in this layer
    for(neuron & n : neurons){
        double temp = 0.0f;

        // for each input weight of this neuron
        for(int i = 0; i < n.weights_from_input.size(); ++i){
            // add the product of the corresponding input and weight to temp
            temp += prev_layer.neurons[i].value * n.weights_from_input[i];
        }

        // apply the activation function and assign the result as the new value
        n.value = n.activation_function(temp);
    }
}

void neuron_layer::set_values(std::vector<float> values){
    for(int i = 0; i < neurons.size(); ++i)
        neurons[i].value = values[i];
}