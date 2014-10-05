#ifndef neural_network_h
#define neural_network_h

#include <vector>

#include "neuron.h"
#include "neuron_layer.h"

class neural_network{

    private:
        neuron_layer input_layer;
        neuron_layer hidden_layer;
        neuron_layer output_layer;

    public:

        neural_network(int input_layer_size, int hidden_layer_size, int output_layer_size);
        float mse(std::vector<float> target_output);

        std::vector<float> process(std::vector<float> input);

};

#endif