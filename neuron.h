#ifndef neuron_h
#define neuron_h
#include <vector>

class neuron{
    public:
        /**
         The value stored at this neuron
        */
        float value;

        /**
         All weights assigned to the input edges to this neuron
        */
        std::vector<float> weights_from_input;

        neuron(int num_inputs);
        void print_weights(void);
};

#endif