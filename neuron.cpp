#include <algorithm>

#include "neuron.h"

neuron::neuron(int num_inputs) : weights_from_input(std::vector<float>(num_inputs)){
    std::transform(weights_from_input.begin(), weights_from_input.end(), weights_from_input.begin(), [](float weight){
        return 0.0f;
    });
}