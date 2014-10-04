#ifndef neuron_h
#define neuron_h
#include <vector>

class neuron{
    private:
        /**
         The value stored at this neuron
        */
        float value;

        /**
         All weights assigned to the input edges to this neuron
        */
        std::vector<float> weights_from_input;

    public:
        
        neuron(int num_inputs);
        void print_weights(void);
        void set_value(float value) {this->value = value;}
        float get_value(void) {return this->value;}
};

#endif