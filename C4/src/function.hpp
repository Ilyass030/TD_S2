#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>




int num_char (const std::string& str, auto it_begin);
std::vector<std::string> split_string(std::string const& str);

bool is_palindrome(std::string str);