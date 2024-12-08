#include <stack>

class MinStack {
  std::stack<int> mainStack;
  std::stack<int> extraStack;

  public:
    MinStack() {
  
    }
    
    void push(int val) {
      mainStack.push(val);
      if (extraStack.empty()) {
        extraStack.push(val);
      } else {
        int min = (extraStack.top() < val ? extraStack.top() : val);
        extraStack.push(min);
      }
    }
    
    void pop() {
      mainStack.pop();
      extraStack.pop();
    }
    
    int top() {
      return mainStack.top();
    }
    int getMin() {
      return extraStack.top();
    }
};
