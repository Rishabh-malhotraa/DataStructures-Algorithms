//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Soltuion
{
private:
  bool next_permutation(string &s, vector<string> &dictionary)
  {
    int n = s.size(), idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
      if (s[i] < s[i + 1])
      {
        idx = i;
        break;
      }
    }
    if (idx == -1)
      return false;

    int candidate = 0;
    for (int i = idx + 1; i < n; i++)
    {
      if (s[i] >= s[idx])
        candidate = i;
      else
        break;
    }

    swap(s[idx], s[candidate]);
    reverse(s.begin() + idx + 1, s.end());
    dictionary.push_back(s);
    return true;
  }

public:
  vector<string> dictionaryPermute(string &s)
  {
    vector<string> dictionary;
    sort(s.begin(), s.end());
    dictionary.push_back(s);
    while (true)
      if (next_permutation(s, dictionary) == false)
        break;
    return dictionary;
  }
};