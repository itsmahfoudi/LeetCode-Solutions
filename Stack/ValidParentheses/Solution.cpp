#include <stack>
#include <string>

class Solution {
  public:
    bool isValid(std::string s) {
      std::stack<char> structure;
      for (char ch : s) {
        if ((ch == '[') || (ch == '(') || (ch == '{')) {
          structure.push(ch);
        } else {
          if (structure.empty()) {
            return false;
          }
          if ((ch==')') && (structure.top() == '(')) {
            structure.pop();
          } else if ((ch==']') && (structure.top() == '[')) {
            structure.pop();
          } else if ((ch=='}') && (structure.top() == '{')) {
            structure.pop();
          } else {
            return false;
          }
        }
      }
      return structure.empty();
    }
};
