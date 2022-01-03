/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int i = 0;
  void update(stack<int> &nums, int &num, char &op)
  {
    if (op == '+')
      nums.push(num);
    else if (op == '-')
      nums.push(-num);

    num = 0;
    op = '+';
  }

  int accumulateStack(stack<int> &nums)
  {
    int sum = 0;
    for (; !nums.empty(); nums.pop())
      sum += nums.top();
    return sum;
  }

public:
  int calculate(string s)
  {
    stack<int> nums;
    char op = '+';
    int n = s.size();
    int num = 0;
    string ops = "+-*/";
    for (; i < n; i++)
    {
      if (isdigit(s[i]))
        num = num * 10 + (s[i] - '0');

      else if (ops.find(s[i]) != string::npos)
        update(nums, num, op), op = s[i];

      else if (s[i] == '(')
        i++, num = calculate(s);

      else if (s[i] == ')')
      {
        update(nums, num, op);
        return accumulateStack(nums);
      }
    }

    update(nums, num, op);
    return accumulateStack(nums);
  }
};

void solve()
{
  string s;
  cin >> s;

  Solution *sol = new Solution();

  cout << sol->calculate(s) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}