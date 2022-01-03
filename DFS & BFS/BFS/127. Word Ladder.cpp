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
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {

    unordered_set<string> s(wordList.begin(), wordList.end());

    if (!s.count(endWord))
      return 0;

    queue<string> q;
    q.push(beginWord);
    int d = 0;
    while (q.empty() == false)
    {
      d++;

      int n = q.size();
      while (n--)
      {
        string front = q.front();
        q.pop();
        for (int i = 0; i < front.size(); i++)
        {
          string next = front;
          for (int ch = 'a'; ch <= 'z'; ch++)
          {
            // now here we need to check if the new string actuall exist of nah
            next[i] = ch;
            if (next == front)
              continue;
            else if (next == endWord)
              return d + 1;
            else if (s.find(next) != s.end())
            {
              q.push(next);
              s.erase(next);
            }
          }
        }
      }
    }
    return 0;
  }
};