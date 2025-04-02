#include <iostream>
#include <string>
// #include <sstream>
// #include <iterator>
#include "function.hpp"

int main()
{
// // Ex1
std::string string_NPI {"3 4 2 ^ 1 5 - 6 ^ / +"};
// std::cout << "Give us a number write on NPI technic ";
//std::getline(std::cin, string_NPI); //j'ai pas vraiment compris l'utilité de getline, pk pas faire directement std::cin??
//std::cout<<std::endl;


// std::vector<std::string> tokens {split_string (string_NPI)};
// std::cout<<"(meth ex1) -> le resutat de votre npi est : "<<npi_evaluate(tokens)<<std::endl;
// std::cout<<std::endl;

// //Ex2
// std::cout<<"(meth ex2) -> le resutat de votre npi est : "<<npi_evaluate(tokenize(tokens))<<std::endl;

//Ex3
std::string infixe {"3 + 4 ^ 2 / ( 1 - 5 ) ^ 6"};
std::vector<Token> npi {infix_to_npi_tokens(infixe)};

std::cout<<"la conversion de "<<infixe<<" en npi est : "<<npi_string(npi)<<std::endl;
std::cout<<"la valeur calculer de cet npi est : "<<npi_evaluate(npi)<<std::endl;
}