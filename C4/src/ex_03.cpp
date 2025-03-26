#include "function.hpp"


int main(){
    std::string str{"akayak"};
    if (is_palindrome(str)){
        std::cout<<"le mot est un palindrome "<<std::endl;
    }
    else{
        std::cout<<"le mot n'est pas un palindrome "<<std::endl;
    }
}