#pragma once


enum class Operator { ADD, SUB, MUL, DIV};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};


std::vector<std::string> split_string(std::string const& s);
//bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);