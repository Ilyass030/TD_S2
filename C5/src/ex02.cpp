#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>
#include <iomanip>


// # liste d'insectes que vous pouvez rencontrer dans ce jardin #
enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

// # une liste des valeurs de l'énumération Insect #
std::vector<Insect> const insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

// # un tableau associatif qui permet de convertir une valeur de l'énumération Insect en une chaîne de caractères #
std::unordered_map<Insect, std::string> const insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

std::vector<int> const expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};


std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t const number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int const seed = std::random_device{}()
) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine{seed};

    auto rand_insect_index { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { rand_insect_index() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        // If we have already seen the same insect, increment the count on the last observation
        if(!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    size_t sum = std::accumulate(counts.begin(), counts.end(),0);
    std::vector<float> proba{};
    for (int elt : counts){
        proba.push_back(static_cast<float>(elt)/sum);
    }
    return proba;
}

int main(){
    //liste d'observation
    std::vector<std::pair<Insect, int>> observation {get_insect_observations(1e5,probabilities_from_count(expected_insect_counts))};
    //table de hashage pour compter le nmbr d'apparition de chaque especes
    std::unordered_map<Insect,int> result {
        {Insect::ClassicBee, 0},
        {Insect::Ladybug, 0},
        {Insect::Butterfly, 0},
        {Insect::Dragonfly, 0},
        {Insect::Ant, 0},
        {Insect::Grasshopper, 0},
        {Insect::Beetle, 0},
        {Insect::Wasp, 0},
        {Insect::Caterpillar, 0},
        {Insect::Spider, 0},
        {Insect::GuimielBee, 0}
    };
    // int i=0;
    
    // for(auto& elt:result){
    //     //std::cout<<"à voir !"<<std::endl;
    //     elt.second=observation[i].second;
    //     auto name { insect_to_string.find(insect_values[i]) };
    //     std::cout<<"le nombre d'apparition de "<<(*name).second<<"est "<<elt.second<<std::endl;
    //     i++;
    // }
    // Compter les insectes
    for (auto const& obs : observation) {
        result[obs.first] += obs.second;
    }
    // Afficher les résultats + Q3
    std::vector<int> counts{};
    for (auto const& elt : result) {
        std::string name = insect_to_string.at(elt.first);
        std::cout << "Le nombre d'apparitions de " << name << " est : " << elt.second << std::endl;
        counts.push_back(elt.second);
    }

    
    std::vector<float>prob_exp {probabilities_from_count(counts)};
    
    std::vector<float>prob_theor {probabilities_from_count(expected_insect_counts)};

    std::cout<<std::endl;
    std::cout<<"Probabilities of observed insects vs expected probabilities"<<std::endl;
    std::cout<<std::endl;

    for(int i =0; i<insect_values.size();i++){
        std::string name = insect_to_string.at(insect_values[i]);
        std::cout<<name<<" : ";
        std::cout << std::fixed << std::setprecision(3);
        std::cout<<prob_exp[i]<<" vs "<<prob_theor[i];
        if(prob_exp[i]-prob_theor[i]<0.01 && prob_exp[i]-prob_theor[i]>-0.01){
            std::cout<<" OK;"<<std::endl;
        }
        else{std::cout<<" BAD;"<<std::endl;}

    }

    return 0;

}