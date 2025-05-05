#include <string>
#include <iostream>


size_t folding_string_hash(std::string const& s, size_t max){
    size_t sum{};
    for (int a : s){
        sum+=a;
    }
    return sum % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t sum{};
    for (int i=0;i<s.size();i++){
        sum+=s[i]*(i+1);
    }
    return sum % max;
}

size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m){
    size_t sum{};
    size_t power=1;
    for (int i=0;i<s.size();i++){
        power*=p;
        sum+=s[i]*power;
    }
    return sum % m;
}




int main(){
    std::string s{"Je suis t'es"};
    std::cout<<folding_string_hash(s,1024)<<std::endl;
    std::cout<<folding_string_ordered_hash(s,1024)<<std::endl;
    std::cout<<polynomial_rolling_hash(s,17,1e3+24)<<std::endl;
}