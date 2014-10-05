#include <algorithm>
#include <iostream>

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
            //std::cout << prev_layer.neurons[i].value << "*" << n.weights_from_input[i] << std::endl;
        }
        //std::cout << std::endl;

        // apply the activation function and assign the result as the new value
        //std::cout << "ws: " << temp << std::endl;
        n.value = n.activation_function(temp);
        //std::cout << "af: " << n.value << std::endl;
    }
}

void neuron_layer::set_values(std::vector<float> values){
    for(int i = 0; i < neurons.size(); ++i)
        neurons[i].value = values[i];
}

void neuron_layer::propagate_error_backwards(float learning_rate, std::vector<float> & errors){
    // for each neuron in this layr
    for(int j = 0; j < neurons.size(); j++){
        // for each incoming edge
        for(int i = 0; i < neurons[j].weights_from_input.size(); ++i){
            // adjust the weight of this edge proportional to the learning rate
            // value at this node and error term

            neurons[j].weights_from_input[i] += learning_rate * errors[j] * neurons[j].value;
        }
    }
}

std::vector<float> neuron_layer::calculate_output_layer_errors(std::vector<float> & target_output, std::vector<float> & actual_output){

}

std::vector<float> neuron_layer::calculate_hidden_layer_errors(std::vector<float> & next_layer_errors){
    // initialize vector of errors the size of this layer
    std::vector<float> errors(neurons.size(), 0.0f);
}