//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// do all these operations in O(1) time

class MinStack
{
public:
  /** initialize your data structure here. */
  stack<int> s, min_stack;

  void push(int val)
  {
    if (min_stack.top() > val)
      min_stack.push(val);
    s.push(val);
  }

  void pop()
  {
    if (s.top() == min_stack.top())
      min_stack.pop();
    s.pop();
  }

  int top()
  {
    return s.top();
  }

  int getMin()
  {
    return min_stack.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */