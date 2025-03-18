#pragma once


enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};


std::vector<std::string> split_string(std::string const& s);
//bool is_floating(std::string const& s);
float npi_evaluate(std::vector<std::string> const& tokens);


Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);

float npi_evaluate(std::vector<Token> const& tokens);


size_t operator_precedence(Operator const op);

std::vector<Token> infix_to_npi_tokens(std::string const& expression);

std::string npi_string (std::vector<Token> npi);