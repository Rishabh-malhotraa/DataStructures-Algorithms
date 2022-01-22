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
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, string> cache;

    vector<string> words;
    set<string> collection;
    stringstream stream(s);
    string word;
    while (getline(stream, word, ' '))
      words.push_back(word);

    if (words.size() != pattern.size())
      return false;

    int n = pattern.size();
    for (int i = 0; i < n; i++)
    {
      char ch = pattern[i];
      string word = words[i];

      if (cache.find(ch) == cache.end())
      {
        if (collection.count(word))
          return false;
        cache.insert({ch, word});
        collection.insert(word);
      }
      else
      {
        if (cache[ch] != word)
          return false;
      }
    }
    return true;
  }
};