/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// L1e2t1C1o1d1e1
class StringIterator
{
  queue<pair<char, int>> stream;
  int idx = 0;

public:
  StringIterator(string s)
  {
    int n = s.size();
    int i = 0;
    while (i < n)
    {
      char ch = s[i++];
      int num = 0;
      while (i < n && isdigit(s[i]) == true)
        num = num * 10 + s[i++] - '0';
      stream.push({ch, num});
    }
  }

  char next()
  {
    if (stream.empty())
      return ' ';

    char ch = stream.front().first;
    if (--stream.front().second == 0)
      stream.pop();

    return ch;
  }

  bool hasNext()
  {
    return stream.size() > 0;
  }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */