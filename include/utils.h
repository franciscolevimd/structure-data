#ifndef UTILS_H_
#define UTILS_H_

#include <string>

bool is_operator(char data);
unsigned short precedence_operator(char operator_v);
std::string infix_to_postfix(std::string expression);
bool is_greater_than(char operator_lef, char operator_right);

#endif // UTILS_H_