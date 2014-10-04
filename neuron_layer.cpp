#include "neuron_layer.h"

neuron_layer::neuron_layer(int size_of_layer, int size_of_prev_layer = 0) :
    neurons(std::vector<neuron>(size_of_layer, neuron(size_of_prev_layer)))
{

}