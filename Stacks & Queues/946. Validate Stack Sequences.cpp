/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/
// s -> 1 2
/*                         |                 |
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.


1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    int i = 0, j = 0;
    int n = pushed.size(), m = popped.size();
    stack<int> s;
    for (int el : pushed)
    {
      s.push(el);
      while (!s.empty() && s.top() == popped[j])
      {
        s.pop();
        j++;
      }
    }
    return (j == n);
  }
};

/* Bootleg Logic
class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    stack<int> s;

    int i = 0, j = 0;
    int n = pushed.size(), m = popped.size();
    stack<int> s;
    while (i < n && j < m)
    {
      if (!s.empty() && s.top() == popped[j])
      {
        s.pop();
        j++;
      }
      else
        s.push(pushed[i++]);
    }

    while (s.empty() == false && j < n)
    {
      if (s.top() == popped[j])
      {
        s.pop();
        j++;
      }
      else
        return false;
    }

    return (s.size() == 0 && j == n);
  }
};
*/