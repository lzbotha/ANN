#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

#include "neuron.h"

neuron::neuron(int num_inputs) : value(0.0f), weights_from_input(std::vector<float>(num_inputs)){

    //TODO: fix the pseudo random number generation going on here
    //      atm each nodes rand num generator has the same seed so all nodes are identical

    std::default_random_engine generator;    

    typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();

    myclock::duration d = myclock::now() - beginning;
    unsigned seed2 = d.count();

    generator.seed (seed2);
    std::uniform_real_distribution<float> distribution(-0.5f,0.5f);

    // Initialize all input weights to random values in the interval [-0.5, 0,5]
    std::transform(weights_from_input.begin(), weights_from_input.end(), weights_from_input.begin(), [& distribution, & generator](float & weight){
        return distribution(generator);
    });
}

void neuron::print_weights(){
    // print each weight to stdout
    for_each(weights_from_input.begin(), weights_from_input.end(), [](float & weight){
        std::cout << weight << std::endl;
    });
}

std::string neuron::to_string(void){
    std::string temp ("Value:\t" + std::to_string(this->value) + "\nInput Weights: ");

    for_each(weights_from_input.begin(), weights_from_input.end(), [& temp](float & weight){
        temp += std::to_string(weight) + " ";
    });

    return std::move(temp);
}