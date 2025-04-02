#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>



bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}
bool is_sorted(std::vector<float> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}
std::vector<float> generate_random_vector_f(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

//*********Ex1*********//
void bubble_sort(std::vector<int> &vec)
{
    int counter = 0;
    do{
        counter = 0;
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] > vec[i+1])
            {
                // int a=vec[i];
                // vec[i]=vec[i++];
                // vec[i++]=a;
                std::swap(vec[i] , vec[i+1]);
                counter++;
            }
        }
    } while (counter != 0);
}


//*********Ex2*********//
void merge_sort_merge(std::vector<float> &vec, size_t left, size_t middle, size_t right);

// void merge_sort(std::vector<float> & vec, size_t const left, size_t const right){
//     size_t middle {left + (right-left)/2};
//     if (right-left<2){ //jsp pk ca ne marche pas avec cette commande
//         return;
//     }
//     merge_sort(vec,left,middle);
//     merge_sort(vec,middle+1,right);
//     merge_sort_merge(vec,left,middle+1,right);
// }

void merge_sort(std::vector<float> &vec, size_t left, size_t right) {
    if (left >= right) return; // Condition d'arrêt correcte

    size_t middle = (left + right) / 2; // Calcul correct du milieu
    //std::cout<<"division"<<std::endl;
    merge_sort(vec, left, middle);      // Tri de la moitié gauche
    merge_sort(vec, middle + 1, right); // Tri de la moitié droite
    //std::cout<<"fusion"<<std::endl;
    merge_sort_merge(vec, left, middle , right); // Fusion des deux moitiés
}

// void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right){
//     std::vector<float>interm{};
//     int i {left};
//     int j {middle};
//     while( i<middle && j<=right)
//     {
//         if(vec[i]>vec[j]){
//             interm.push_back(vec[j]);
//             j++;
//         }
//         else{
//             interm.push_back(vec[i]);
//             i++;
//         }
//     }
//     if(i==middle-1){
//         //interm.asign(vec[j],vec.end());
//         std::copy(vec[j],vec.end(),interm[j]);
//     }
//     else{
//         interm.asign(vec.begin() + i, vec.begin() + middle);//vec[i],vec[middle-1]
//     }
//     std::copy(interm.begin(),interm.end(),vec.begin());

//     // for(int i=left; i<middle;i++){
//     //     for(int j=middle; j<=right;j++){
//     //         if(vec[i]>vec[j]){
//     //             interm.push_back(vec[j]);
//     //         }
//     //         else {break;}
//     //     }
//     // }

// }
void merge_sort_merge(std::vector<float> &vec, size_t left, size_t middle, size_t right) {
    std::vector<float> interm;
    //interm.reserve(right - left + 1); // Optimisation pour éviter les reallocations

    size_t i = left, j = middle+1;
    size_t k =  left;

    while (i <= middle && j <= right) {
        if (vec[i] > vec[j]) {
            interm.push_back(vec[j]);
            j++;
        } else {
            interm.push_back(vec[i]);
            i++;
        }
    }

    // Ajouter les éléments restants du premier sous-tableau
    while (i <= middle) {
        interm.push_back(vec[i]);
        i++;
    }

    // Ajouter les éléments restants du second sous-tableau
    while (j <= right) {
        interm.push_back(vec[j]);
        j++;
    }
    //std::cout<<"ca marche??"<<std::endl;
    // Copier les valeurs triées dans le vecteur d'origine
    std::copy(interm.begin(), interm.end(), vec.begin() + left);
    //std::cout<<"ouii!"<<std::endl;
}

// std::vector <int>interm{1, 2, 2, 3, 4, 8, 12};
int search(std::vector<int>& vec, int x, size_t left, size_t right){
    if (left > right) return -1;
    // size_t left = 0;
    // size_t right =  vec.size();
    int middle=(left+right)/2;
    // while (vec[middle] < x){ //en itirative
    //     left=middle;
    //     middle=(left+right)/2;
    // }
    // if (vec[middle]==x) return middle;
    //en recu
    // while (right!=left && middle !=x){
    if (vec[middle]==x)return middle;
    
    else if(vec[middle]<x){
        return search(vec,x,middle,right);
    }
    else {return search(vec,x,left,middle);}
    //else return -1;
    // }
}