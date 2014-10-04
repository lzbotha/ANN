#include <algorithm>

#include "neuron_layer.h"

neuron_layer::neuron_layer(int size_of_layer, int size_of_prev_layer = 0) :
    neurons(std::vector<neuron>(size_of_layer, neuron(size_of_prev_layer)))
{

}

std::string neuron_layer::to_string(void){
    std::string temp;
    std::for_each(neurons.begin(), neurons.end(), [& temp](neuron & n){
        temp += n.to_string() + "\n";
    });

    return std::move(temp);
}