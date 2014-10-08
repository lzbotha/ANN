#include <iostream>
#include <fstream>

#include "neural_network.h"

neural_network::neural_network(int input_layer_size, int hidden_layer_size, int output_layer_size) :
input_layer(neuron_layer(input_layer_size)),
hidden_layer(neuron_layer(hidden_layer_size, input_layer_size)),
output_layer(neuron_layer(output_layer_size, hidden_layer_size))
{

}

float neural_network::mse(std::vector<float> target_output){
    /*
    sum <- 0
    for i in 0...outputLayerSize -1 do
        err <- desiredoutput[i] - actualoutput[i]
        sum <- sum + err*err
    return sum / outputLayerSize
    */

    float sum = 0;
    for (int i = 0; i < this->output_layer.neurons.size(); ++i){
        float err = target_output[i] - this->output_layer.neurons[i].value;
        sum += err * err;
    }

    return sum / this->output_layer.neurons.size();
}

std::vector<float> neural_network::process(std::vector<float> input){
    this->input_layer.set_values(input);
    
    this->hidden_layer.feed_forward_from(this->input_layer);
    this->output_layer.feed_forward_from(this->hidden_layer);

    return std::move(output_layer.get_values());
}


std::string neural_network::to_string(void){
    std::string temp = "Input Layer\n";
    temp += this->input_layer.to_string();
    temp += "Hidden Layer\n";
    temp += this->hidden_layer.to_string();
    temp += "Output Layer\n";
    temp += this->output_layer.to_string();
    
    return std::move(temp);
}

void neural_network::propagate_backwards(float learning_rate, std::vector<float> target_outputs){
    std::vector<float> output_layer_errors = this->output_layer.calculate_output_layer_errors(target_outputs);

    this->output_layer.propagate_error_backwards(learning_rate, output_layer_errors);

    std::vector<float> hidden_layer_errors = this->hidden_layer.calculate_hidden_layer_errors(this->output_layer, output_layer_errors);

    this->hidden_layer.propagate_error_backwards(learning_rate, hidden_layer_errors);
}

bool neural_network::train(std::string training_data_filename, float learning_rate, int iterations, float mse_cutoff){
    using namespace std;

    int iter = 0;
    if(iterations == -1)
        iter = -2;

    float mse = mse_cutoff + 1.0f;

    // while the algorithm has not converged or reached the cutoff point continue training
    while(mse > mse_cutoff && iter < iterations){
        mse = 0.0f;
        ifstream file(training_data_filename);

        // if there was an error opening the file return false
        if(!file.is_open()){
            cout << "File error" << endl;
            return false;
        }


        int training_examples;
        file >> training_examples;
        // cout << "Number of training examples: " << training_examples << endl;

        // for each training example
        for(int i = 0; i < training_examples; ++i){
            // get the inputs
            vector<float> inputs(this->input_layer.neurons.size(), 0.0f);
            for(float & f : inputs){
                file >> f;
                // cout << f << " ";
            }
            // cout << endl;

            // get the outputs
            vector<float> outputs(this->output_layer.neurons.size(), 0.0f);
            for(float & f : outputs){
                file >> f;
                // cout << f << " ";
            }
            // cout << endl;

            // feed the inputs forward through the network
            this->process(inputs);

            // propagate the error backwards
            this->propagate_backwards(learning_rate, outputs);

            mse += this->mse(outputs);
        }

        file.close();

        mse /= training_examples;
        // cout << mse << endl;
        if(iterations != -1){
            ++iter;
        }
    }

    return true;
}