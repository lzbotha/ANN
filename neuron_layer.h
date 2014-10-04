#ifndef neuron_layer_h
#define neuron_layer_h

#include <vector>
#include <string>

#include "neuron.h"

class neuron_layer{
    private:
        std::vector<neuron> neurons;

    public:
        neuron_layer(int size_of_layer, int size_of_prev_layer);
        std::string to_string(void);

};

#endif