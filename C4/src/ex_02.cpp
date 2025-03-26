#include<iostream>
#include<string>
#include "function.hpp"



int main(){
    std::string str{"Je m'appelle"};
    std::cout<<"la taille de votre premier mot est "<<num_char(str)<<std::endl;

    
    for(auto word:split_string(str)){
        std::cout<<word<<" ,";
    }
}