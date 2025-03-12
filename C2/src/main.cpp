#include <iostream>
#include <string>
// #include <sstream>
// #include <iterator>
#include "function.hpp"

int main()
{
// Ex1
std::string string_NPI {};
std::cout << "Give us a number write on NPI technic ";
std::getline(std::cin, string_NPI); //j'ai pas vraiment compris l'utilité de getline, pk pas faire directement std::cin??
std::cout<<std::endl;


std::vector<std::string> tokens {split_string (string_NPI)};
std::cout<<"le resutat de votre npi est : "<<npi_evaluate(tokens)<<std::endl;

//Ex2

}