#include <iostream>
#include <vector>
#include "function.hpp"
#include "ScopedTimer.hpp"

int main()
{
    // std::vector<int> array{2, 8, 5, 4, 1, 6, 7, 3, 9};
    std::vector<int> array{generate_random_vector(100,100)};

    // std::vector<float> array_f{2, 8, 5, 4, 1, 6, 7, 3, 9};
    std::vector<float> array_f{generate_random_vector_f(100,100)};

    //*********Ex1*********//
    {
        ScopedTimer timer("chrono tri à bulme");
        bubble_sort(array);
    }
    {
        ScopedTimer timer("chrono tri fusion");
        merge_sort(array_f,0,array_f.size());
    }

    
    
    if (is_sorted(array))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

}