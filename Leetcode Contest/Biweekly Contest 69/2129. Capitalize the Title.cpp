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
  string capitalizeTitle(string title)
  {
    vector<string> words;
    stringstream ss(title);
    string token;
    string text;
    while (getline(ss, token, ' '))
    {
      if (token.size() <= 2)
      {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        text += token + ' ';
      }
      else
      {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        transform(token.begin(), token.begin() + 1, token.begin(), ::toupper);
        text += token + ' ';
      }
    }
    text.pop_back();
    return text;
  }
};