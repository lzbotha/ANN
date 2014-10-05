

#include "neural_network.h"

neural_network::neural_network(int input_layer_size, int hidden_layer_size, int output_layer_size) :
input_layer(neuron_layer(input_layer_size)),
hidden_layer(neuron_layer(hidden_layer_size, input_layer_size)),
output_layer(neuron_layer(output_layer_size, hidden_layer_size))
{

}