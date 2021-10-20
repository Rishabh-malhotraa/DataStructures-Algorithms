/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
1 - 1
2 - 1
3 - 1

h[s] || h[g]

  0 1 2 1 1  ->   secret
  0 1 1 1 0  ->   guess

  b= 2
  c= =

  [2]   +1
  [1]   -1

  bulls = 1

  cows = 1

*/

class Solution
{
public:
  string getHint(string secret, string guess)
  {
    unordered_map<char, int> cache;
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); i++)
    {
      char s = secret[i], g = guess[i];
      if (secret[i] == guess[i])
        bulls++;
      else
      {
        if (cache[s] < 0)
          cows++;
        if (cache[g] > 0)
          cows++;
        cache[s]++, cache[g]--;
      }
    }
    string code = to_string(bulls) + "A" + to_string(cows) + "B";
    return code;
  }
};

class Solution
{
public:
  string getHint(string secret, string guess)
  {

    unordered_map<char, int> freq;

    for (char &ch : secret)
      freq[ch]++;

    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); i++)
      if (secret[i] == guess[i])
        freq[secret[i]]--, bulls++;

    for (int i = 0; i < secret.size(); i++)
      if (secret[i] != guess[i] && freq[guess[i]] != 0)
        freq[guess[i]]--, cows++;

    string code = to_string(bulls) + "A" + to_string(cows) + "B";

    return code;
  }
};