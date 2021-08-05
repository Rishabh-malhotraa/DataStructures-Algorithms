//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool isOperator(string &token)
  {
    string expression = "+-*/";
    return expression.find(token) != string::npos;
  }

  int evaluate(int a, int b, string operand)
  {
    if (operand == "+")
      return a + b;
    if (operand == "-")
      return a - b;
    if (operand == "*")
      return a * b;
    if (operand == "/")
      return a / b;
  }

public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> s;

    for (string token : tokens)
    {
      if (isOperator(token))
      {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();

        s.push(evaluate(a, b, token));
      }
      else
      {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};