#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <numeric>
#include "function.hpp"




int num_char (const std::string& str, auto it_begin){
    auto it {std::find(it_begin,str.end(),' ')};
    if(it != str.end()){
        return std::distance(it_begin,it);
    }
    return std::distance(it_begin,str.end());
}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> vec{};
    auto it_begin{str.begin()};
    auto it {std::find(it_begin,str.end(),' ')};

    while (it!=str.end()){
        it_begin=it+1;
        it+=num_char(str,it_begin);
        std::string word{std::accumulate(it_begin,it,std::string{},
            [](auto acc,auto elt){return acc+elt;})};
        vec.push_back(word);
    }
    return vec;
}

bool is_palindrome(std::string str){
    // for(auto it:str){
    //     if()
    // }
    return std::equal(str.begin(),str.end(),str.rbegin());
}
