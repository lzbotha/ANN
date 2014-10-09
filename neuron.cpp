#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

#include "neuron.h"

neuron::neuron(int num_inputs) : value(0.0), weighted_sum(0.0), weights_from_input(std::vector<double>(num_inputs)){

    std::default_random_engine generator;

    // Get seed for the random number generator
    std::chrono::high_resolution_clock::time_point beginning = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::duration d = std::chrono::high_resolution_clock::now() - beginning;
    unsigned seed = d.count();

    // seed it
    generator.seed (seed);

    // random values on interval
    std::uniform_real_distribution<double> distribution(-5.0, 5.0);

    distribution(generator);

    // Initialize all input weights to random values on the interval
    std::transform(weights_from_input.begin(), weights_from_input.end(), weights_from_input.begin(), [& distribution, & generator](double & weight){
        return distribution(generator);
    });
}

void neuron::print_weights(){
    // print each weight to stdout
    for_each(weights_from_input.begin(), weights_from_input.end(), [](double & weight){
        std::cout << weight << std::endl;
    });
}

std::string neuron::to_string(void){
    std::string temp ("Value:\t" + std::to_string(this->value) + "\nWeighted Sum: " + std::to_string(this->weighted_sum) +  "\nInput Weights: ");

    for_each(weights_from_input.begin(), weights_from_input.end(), [& temp](double & weight){
        temp += std::to_string(weight) + " ";
    });

    return std::move(temp);
}

double neuron::activation_function(double x){
    return 1 / (1 + exp(- x));
}

double neuron::dv_activation_function(double x){
    return this->activation_function(x) * (1 - this->activation_function(x));
}