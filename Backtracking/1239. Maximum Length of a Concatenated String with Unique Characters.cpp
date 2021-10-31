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
public:
  int maxLength(vector<string> &arr, string word = "", int idx = 0)
  {
    unordered_set<char> keys(word.begin(), word.end());
    if (keys.size() != word.size())
      return 0;

    int result = word.size();
    for (int i = idx; i < arr.size(); i++)
      result = max(result, maxLength(arr, word + arr[i], i + 1));

    return result;
  }
};
