#include <iostream>
#include <vector>
#include "function.hpp"
#include "ScopedTimer.hpp"

int main()
{
    // std::vector<int> array{2, 8, 5, 4, 1, 6, 7, 3, 9};
    std::vector<int> array{generate_random_vector(100,100)};

    //std::vector<float> array_f{9,5,32,5,90,4,12,56,8,43};
    std::vector<float> array_f{generate_random_vector_f(100,100)};

    //*********Ex1*********//
    // {
    //     ScopedTimer timer("chrono tri à bulme");
    //     bubble_sort(array);
    // }
    // //std::cout<<"marche?";
    // {
    //     ScopedTimer timer("chrono tri fusion");
    //     merge_sort(array_f,0,array_f.size());
    // }
    // for(float x:array_f){
    //     std::cout<<x<<",";
    // }
    // std::cout<<std::endl;

    // merge_sort(array_f);

    // for(float x:array_f){
    //     std::cout<<x<<",";
    // }
    
    // if (is_sorted(array_f))
    // {
    //     std::cout << "Le tableau est trié" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Le tableau n'est pas trié" << std::endl;
    // }

    //*********Ex4*********//
    std::vector <int>vec{1, 2, 2, 3,3, 4, 8, 12, 15,20,21};
    int it = search(vec, 8,0,vec.size());
    std::cout<<it;
}