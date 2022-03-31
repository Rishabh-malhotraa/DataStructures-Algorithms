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
  string getFirstWord(string &word)
  {
    int len = word.find(' ') != string::npos ? word.find(' ') : word.size();
    return word.substr(0, len);
  }
  string getLastWord(string &word)
  {
    int idx = word.rfind(' ') != string::npos ? word.rfind(' ') + 1 : 0;
    return word.substr(idx);
  }

  string mergeStrings(string a, string b)
  {
    int len = b.find(' ') != string::npos ? b.find(' ') : b.size();
    return a + b.substr(len);
  }

public:
  vector<string> beforeAndAfterPuzzles(vector<string> &phrases)
  {
    vector<string> result;
    int n = phrases.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        if (getLastWord(phrases[i]) == getFirstWord(phrases[j]))
          result.push_back(mergeStrings(phrases[i], phrases[j]));
      }
    }
    set<string> temp(result.begin(), result.end());
    return vector<string>(temp.begin(), temp.end());
  }
};