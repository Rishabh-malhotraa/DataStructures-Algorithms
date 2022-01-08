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
  string reorderSpaces(string text)
  {
    vector<string> words;
    int count = 0;
    string currWord = "";

    for (char &ch : text)
    {
      if (ch == ' ')
      {
        count++;
        if (currWord.size())
          words.push_back(currWord);
        currWord = "";
      }
      else
        currWord.push_back(ch);
    }
    if (currWord.size())
      words.push_back(currWord);

    int n = words.size();

    int addSpace = (n - 1) ? count / (n - 1) : 0;
    int extraSpaces = (n - 1) ? count % (n - 1) : count;

    text = "";
    for (string &word : words)
    {
      if (&word == &words.back())
        text += word;
      else
        text += word + string(addSpace, ' ');
    }
    text += string(extraSpaces, ' ');
    return text;
  }
};
//"  this   is  a sentence "