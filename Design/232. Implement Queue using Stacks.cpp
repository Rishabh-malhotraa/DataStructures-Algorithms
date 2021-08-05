//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// push at front and pop at back
// You could have O(1) push and O(N) Pop
// OR
// You can have O(n) push and O(1) POP

class MyQueue
{
public:
  /** Initialize your data structure here. */
  stack<int> s1;
  stack<int> s2;
  int front;
  MyQueue()
  {
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    if (s1.empty() == true)
      front = x;
    s1.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    while (s1.size() > 1)
    {
      s2.push(s1.top());
      s1.pop();
    }
    front = s2.empty() ? 0 : s2.top();
    int popped = s1.top();
    s1.pop();
    while (!s2.empty())
    {
      s1.push(s2.top());
      s2.pop();
    }
    return popped;
  }

  /** Get the front element. */
  int peek()
  {
    return front;
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return s1.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */