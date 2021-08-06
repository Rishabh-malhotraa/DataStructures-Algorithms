//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// This Took more time then it should have

// Follow Up how woud you do this for k deletions

class Solution
{
private:
  bool checkPalindrome(int left, int right, string &s)
  {
    while (left <= right)
      if (s[left++] != s[right--])
        return false;

    return true;
  }

public:
  bool validPalindrome(string s)
  {
    int l = 0, r = s.size() - 1;

    while (l <= r)
      if (s[l++] != s[r--])
        return checkPalindrome(l, r + 1, s) || checkPalindrome(l - 1, r, s);

    return true;
  }
};