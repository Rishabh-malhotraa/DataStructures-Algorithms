/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class RabinKarp
{
private:
  const int MOD = 1e9 + 7;
  const int base = 229;
  vector<long long> power;
  string text;

  long long getHash(string s)
  {
    int n = s.size();
    long long hash = 0;
    for (int i = 0; i < n; i++)
    {
      int charValue = s[i] - 'A' + 1;
      hash = (hash * base + charValue) % MOD;
    }
    return hash;
  }

  bool checkStrings(string& pattern, string& text, int idx)
  {
    for (int i = 0; i < pattern.size(); i++)
      if (pattern[i] != text[idx + i])
        return false;
    return true;
  }

public:
  RabinKarp(string text)
  {
    this->text = text;
    int n = text.size();
    power.assign(n + 1, 1);

    for (int i = 0; i < n; i++)
      power[i + 1] = (power[i] * base) % MOD;

  }

  // get the occurances of string position of pattern match
  vector<int> occurances(string pattern)
  {
    vector<int> indices;

    long long patternHash = getHash(pattern);
    int n = text.size(), m = pattern.size();


    long long windowHash = getHash(text.substr(0, m));


    if (windowHash == patternHash && checkStrings(pattern, text, 0))
      indices.push_back(0);


    for (int i = 1; i <= n - m; i++)
    {
      int charOut = tolower(text[i - 1]) - 'a' + 1;
      int charIn = tolower(text[i + m - 1]) - 'a' + 1;

      windowHash = (windowHash - (charOut * power[m - 1]) % MOD + MOD) % MOD;
      windowHash = ((windowHash * base) + charIn) % MOD;

      if (windowHash == patternHash && checkStrings(pattern, text, i))
        indices.push_back(i);
    }
    return indices;
  }
};