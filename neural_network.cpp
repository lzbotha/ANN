

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
    for (int i = 0; this->output_layer.neurons.size(); ++i){
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