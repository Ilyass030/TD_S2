#include "function.hpp"


int main(){
    std::vector<int> vec {1,2,3,4,5};
    std::cout<<"la somme du carré dee vec est " << sum_square(vec) << std::endl;
    std::cout<<"la somme des nombres pairs de vec est " << sum_even(vec);
}