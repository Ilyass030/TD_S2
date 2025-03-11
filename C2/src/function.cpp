#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

void string_NPI(){

}
std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s){ //comment utiliser isdigit??
    bool answer =1;
    while( answer =!0){
        for (char c:s){
            if (static_cast<int>(c) >47 && (int)c<58 || (int)c==46){
                answer = true;
            }
            answer = false;
        }
    }
    return answer;
}

float npi_evaluate(std::vector<std::string> const& tokens){
    
}
