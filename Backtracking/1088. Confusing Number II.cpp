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
  int count = 0;

  bool isConfusingNumber(string &num)
  {
    string num_copy = num;
    for (char &ch : num_copy)
    {
      if (ch == '6')
        ch = '9';
      else if (ch == '9')
        ch = '6';
    }
    reverse(num_copy.begin(), num_copy.end());
    return num != num_copy;
  }

  void dfs(string &num, vector<char> &nums, int &N)
  {
    if (num.size() && stol(num) > N)
      return;

    if (num.size() && stol(num) <= N && isConfusingNumber(num))
      count++;

    for (char &ch : nums)
    {
      if (ch == '0' && num.size() == 0)
        continue;
      num.push_back(ch);
      dfs(num, nums, N);
      num.pop_back();
    }
  }

public:
  int confusingNumberII(int n)
  {
    vector<char> nums = {'0', '1', '6', '8', '9'};
    string s = "";
    dfs(s, nums, n);
    return count;
  }
};