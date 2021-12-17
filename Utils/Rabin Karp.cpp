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
  vector<long long> baseHash, textHash;
  string text;

  vector<long long> getHash(string s)
  {
    int n = s.size();
    vector<long long> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
      int ch = s[i] - 'a' + 1;
      hash[i + 1] = (hash[i] + ch * baseHash[i]) % MOD;
    }
    return hash;
  }

public:
  RabinKarp(string text)
  {
    this->text = text;
    int n = text.size();
    baseHash.assign(n + 1, 1);
    textHash.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
      baseHash[i + 1] = (baseHash[i] * base) % MOD;

    textHash = getHash(text);
  }

  // get the occurances of string position of pattern match
  vector<int> occurances(string pattern)
  {
    vector<int> indices;

    long long patternHash = getHash(pattern).back();
    int n = text.size(), m = pattern.size();

    for (int i = 0; i <= n - m; i++)
    {
      long long windowHash = (textHash[i + m] - textHash[i] + MOD) % MOD;

      if (windowHash == (patternHash * baseHash[i]) % MOD)
        indices.push_back(i);
    }
    return indices;
  }
};