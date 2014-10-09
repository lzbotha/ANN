#ifndef neuron_layer_h
#define neuron_layer_h

#include <vector>
#include <string>

#include "neuron.h"

class neuron_layer{
    friend class neural_network;
    private:
        std::vector<neuron> neurons;

    public:
        neuron_layer(int size_of_layer, int size_of_prev_layer = 0);
        std::string to_string(void);
        void feed_forward_from(const neuron_layer & prev_layer);
        void propagate_error_backwards(double learning_rate, std::vector<double> & errors);
        void set_values(std::vector<double> values);
        std::vector<double> get_values(void);
        std::vector<double> calculate_output_layer_errors(std::vector<double> & target_output);
        std::vector<double> calculate_hidden_layer_errors(const neuron_layer & next_layer, std::vector<double> & next_layer_errors);
};

#endif