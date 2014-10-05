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
        void feed_forward_from(const neuron_layer & prev_layer);
        void propagate_error_backwards(float learning_rate, std::vector<float> & errors);
        void set_values(std::vector<float> values);
        std::vector<float> calculate_output_layer_errors(std::vector<float> & target_output, std::vector<float> & actual_output);
        std::vector<float> calculate_hidden_layer_errors(const neuron_layer & next_layer, std::vector<float> & next_layer_errors);
};

#endif