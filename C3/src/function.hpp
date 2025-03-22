#pragma once
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec);
bool is_sorted(std::vector<float> const& vec);
std::vector<int> generate_random_vector(size_t const size, int const max = 100);
std::vector<float> generate_random_vector_f(size_t const size, int const max = 100);

//void swap(int x, int y);
void bubble_sort(std::vector<int> & vec);

//size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}