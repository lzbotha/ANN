#ifndef neuron_layer_h
#define neuron_layer_h

#include <vector>
#include <string>

#include "neuron.h"

class neuron_layer{
    private:
        std::vector<neuron> neurons;
        int id;

    public:
        neuron_layer(int size_of_layer, int size_of_prev_layer = 0);
        std::string to_string(void);
        void feed_forward(const neuron_layer & prev_layer);

};

#endif