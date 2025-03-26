#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <numeric>
#include "function.hpp"

bool find(std::vector <int>& vect,const int& x){
    std::vector<int>::iterator it {std::find(vect.begin(),vect.end(),x)};
    if (it!= vect.end()){
        return true;
    }
    return false;
}

int counter (std::vector<int>& vec,const int& x){
    return std::count(vec.begin(),vec.end(),x); 
}

int main(){
    srand(time(nullptr)); // Initialisation du générateur de nombres pseudo-aléatoires avec une graine aléatoire
    std::vector<int> vec {};
    for (int i=0; i<10;i++){
        //int random_number { rand() % 100 +1 }; // Génération d'un nombre aléatoire
        //vec.push_back(random_number);
        vec.push_back(rand() % 100 +1);
    }

    std::sort(vec.begin(),vec.end());

    //>>>>> Pour afficher les elmts de vec <<<<<<<
    // for(std::vector<int>::iterator it = vec.begin();it != vec.end();it++){
    //     std::cout<<*it<<std::endl;
    // }



    int nbr{};
    std::cout<<"quel nombre cherchez vous? "<<std::endl;
    std::cin>>nbr;
    if (find(vec,nbr)){
        std::cout<<"le nombre recherché est dans la lite. Et est répéter "<<counter(vec,nbr)<<std::endl;
    }
    else{
        std::cout<<"le nombre recherché ne fait pas parti dee la lite. "<<std::endl;
    }

    int sum{std::accumulate(vec.begin(),vec.end(),0,
    [](int acc,int elt){return acc+elt;})};
    std::cout<<"la somme des elements du vect est "<<sum<<std::endl;

}