#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
      std::unordered_map<std::string, char> operation = {{"+",'+'},{"-",'-'},{"*",'*'},{"/",'/'}};
      int operand1, operand2, result = 0; 
      std::stack<int> operands; 
      for (std::string str : tokens) {
        if (operation.count(str) == 0) {
            operands.push(std::stoi(str));
        } else {
          if (operands.empty()) {
            continue;
          }
          operand2 = operands.top();
          operands.pop();
          operand1 = operands.top();
          operands.pop();
          switch (operation[str]) {
            case '*':
              result = operand1 * operand2; 
              operands.push(result);
              break;
            case '/':
              result = operand1 / operand2; 
              operands.push(result);
              break;
            case '+':
              result = operand1 + operand2; 
              operands.push(result);
              break;
            case '-':
              result = operand1 - operand2; 
              operands.push(result);
              break;
            default:
              break;
          }
        }
      }
      return result;
    }
};
