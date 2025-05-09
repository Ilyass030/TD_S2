#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <cassert>
#include <stack>
#include "function.hpp"

//*******Ex_1************//

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s){ //comment utiliser isdigit??
    bool answer =true;
        for (char c:s){
            if (!(std::isdigit(c) || c=='.')){
                answer = false;
            };
        }
        return answer;
    
}

float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> stack {};
    for (std::size_t i=0; i< tokens.size() ;i++){
        if (is_floating(tokens[i])){
            stack.push(std::stof(tokens[i]));
        }
        else {
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            if (tokens[i] =="+"){
                float result { leftOperand + rightOperand};
                stack.push(result);
                continue;
            }
            else if (tokens[i] =="-"){
                float result { leftOperand - rightOperand};
                stack.push(result);
                continue;
            }
            else if (tokens[i] =="*"){
                float result { leftOperand * rightOperand};
                stack.push(result);
                continue;
            }
            else if (tokens[i] =="/"){
                float result { leftOperand / rightOperand};
                stack.push(result);
                continue;
            }
            else if(tokens[i] =="^"){
                float result { pow(leftOperand, rightOperand)};
                stack.push(result);
                continue;
            }
        }
    }
    return stack.top();
}

//*******Ex_2************//

Token make_token(float value){
    Token token {};
    token.type=TokenType::OPERAND;
    token.value=value;
    return token;
}
Token make_token(Operator op){
    Token token {};
    token.type=TokenType::OPERATOR;
    token.op=op;
    return token;
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens;
    for (std::string str:words){
        if ( is_floating(str)) {
            tokens.push_back(make_token(stof(str)));
            continue;
        }
        else {
            if (str =="+"){
                tokens.push_back(make_token(Operator::ADD));
                continue;
            }
            else if (str =="-"){
                tokens.push_back(make_token(Operator::SUB));
                continue;
            }
            else if (str =="*"){
                tokens.push_back(make_token(Operator::MUL));
                continue;
            }
            else if (str =="/"){
                tokens.push_back(make_token(Operator::DIV));
                continue;
            }
            else if (str =="^"){
                tokens.push_back(make_token(Operator::POW));
                continue;
            }
            else if (str =="("){
                tokens.push_back(make_token(Operator::OPEN_PAREN));
                continue;
            }
            else if (str ==")"){
                tokens.push_back(make_token(Operator::CLOSE_PAREN));
                continue;
            }
        }
    }
    return tokens;
}


float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack {};
    //stack.push(tokens[0].value);
    for (Token t:tokens){
        if(t.type == TokenType::OPERAND){
            stack.push(t.value);
        }
        else{
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            if (t.op ==Operator::ADD){
                float result { leftOperand + rightOperand};
                stack.push(result);
                continue;
            }
            else if (t.op ==Operator::SUB){
                float result { leftOperand - rightOperand};
                stack.push(result);
                continue;
            }
            else if (t.op ==Operator::MUL){
                float result { leftOperand * rightOperand};
                stack.push(result);
                continue;
            }
            else if (t.op ==Operator::DIV){
                float result { leftOperand / rightOperand};
                stack.push(result);
                continue;
            }
            else if(t.op ==Operator::POW){
                float result { pow(leftOperand, rightOperand)};
                stack.push(result);
                continue;
            }
        }
    }
    return stack.top();
}


//*******Ex_3************//

size_t operator_precedence(Operator const op){
    if (op == Operator::ADD || op == Operator::SUB){
        return 2;
    }
    else if (op == Operator::MUL || op == Operator::DIV){
        return 3;
    }
    else if (op == Operator::POW){
        return 4;
    }
    return 0;
    assert(false);
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression){
    std::vector<Token> resp;
    std::stack<Token> pile_op;
    //int deg;
    auto const tokens = tokenize(split_string(expression));
    for (Token t:tokens){
        if (t.type == TokenType::OPERAND){
            resp.push_back(t);
        }
        else{
            if (t.op== Operator::OPEN_PAREN){
                pile_op.push(t);
            }
            else if(t.op== Operator::CLOSE_PAREN){
                while(pile_op.top().op!= Operator::OPEN_PAREN){
                    resp.push_back(pile_op.top());
                    pile_op.pop();
                }
                pile_op.pop();
            }
            else { 
                while (size(pile_op)!=0 && operator_precedence(t.op) <= operator_precedence(pile_op.top().op)){
                    resp.push_back(pile_op.top());
                    pile_op.pop();
                }
                pile_op.push(t);
            }
        }
    }
    while (size(pile_op)!=0){
        resp.push_back(pile_op.top());
        pile_op.pop();
    }
    return resp;

}

std::string npi_string (std::vector<Token> npi){
    std::string str{};
    for (Token t : npi){
        if(t.type==TokenType::OPERATOR && t.op==Operator::ADD){
            str+="+ ";
        }
        else if(t.type==TokenType::OPERATOR && t.op==Operator::SUB){
            str+="- ";
        }
        else if(t.type==TokenType::OPERATOR && t.op==Operator::MUL){
            str+="* ";
        }
        else if(t.type==TokenType::OPERATOR && t.op==Operator::DIV){
            str+="/ ";
        }
        else if(t.type==TokenType::OPERATOR && t.op==Operator::POW){
            str+="^ ";
        }
        else{
            str+=std::to_string(t.value);
            str+=' ';
        }
    }
    return str;
}