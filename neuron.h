#ifndef neuron_h
#define neuron_h
#include <string>
#include <vector>

class neuron{
    friend class neuron_layer;
    friend class neural_network;
    
    private:
        /**
         The value stored at this neuron
        */
        double value;

        double weighted_sum;

        /**
         All weights assigned to the input edges to this neuron
        */
        std::vector<double> weights_from_input;
        

    public:
        
        neuron(int num_inputs);
        void print_weights(void);
        std::string to_string(void);
        void set_value(double value) {this->value = value;}
        double get_value(void) {return this->value;}

        double activation_function(double);
        double dv_activation_function(double x);
};


#endif