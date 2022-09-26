#include "utils.h"

#include <stack>

using namespace std;

bool is_operator(char data) {
  return data == '^' || data == '*' || data == '/' || data == '+' ||
         data == '-';
}

unsigned short precedence_operator(char operator_v) {
  if (operator_v == '^') {
    return 0;
  }
  if (operator_v == '*' || operator_v == '/') {
    return 1;
  }
  if (operator_v == '+' || operator_v == '-') {
    return 2;
  }
  return 10;
}

string infix_to_postfix(string expression) {
  if (expression.length() == 0) {
    return expression;
  }
  string result = "";
  stack<char> operators_stack;
  unsigned short last_value = 0;
  unsigned short new_value = 0;
  for (string::iterator it = expression.begin(); it != expression.end(); it++) {
    if (is_operator(*it)) {
      if (operators_stack.size() > 0 &&
          is_greater_than(operators_stack.top(), *it)) {
        result.push_back(operators_stack.top());
        operators_stack.pop();
      }
      operators_stack.push(*it);
    } else {
      result.push_back(*it);
    }
  }
  while (operators_stack.size() > 0) {
    result.push_back(operators_stack.top());
    operators_stack.pop();
  }
  return result;
}

bool is_greater_than(char operator_left, char operator_right) {
  return (precedence_operator(operator_left) <
          precedence_operator(operator_right));
}
