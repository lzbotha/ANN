#ifndef neuron_h
#define neuron_h
#include <string>
#include <vector>

class neuron{
    friend class neuron_layer;
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
        std::string to_string(void);
        void set_value(float value) {this->value = value;}
        float get_value(void) {return this->value;}

        float activation_function(float);
        float dv_activation_function(float x);
};


#endif