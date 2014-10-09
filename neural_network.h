#ifndef neural_network_h
#define neural_network_h

#include <vector>

#include "neuron.h"
#include "neuron_layer.h"

class neural_network{

    private:
        neuron_layer input_layer;
        neuron_layer hidden_layer1;
        neuron_layer hidden_layer2;
        neuron_layer output_layer;

        int num_hidden_layers;

    public:

        neural_network(int input_layer_size, int hidden_layer_size, int output_layer_size);
        neural_network(int input_layer_size, int hidden_layer1_size, int hidden_layer2_size, int output_layer_size);
        double mse(std::vector<double> target_output);

        std::vector<double> process(std::vector<double> input);
        void propagate_backwards(double learning_rate, std::vector<double> target_outputs);
        std::string to_string(void);

        bool train(std::string training_data_filename, double learning_rate, int iterations, double mse_cutoff);
};

#endif