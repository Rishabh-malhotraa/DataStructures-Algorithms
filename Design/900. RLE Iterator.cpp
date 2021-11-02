/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class RLEIterator
{
  vector<int> encoding;
  int exhausted = 0;
  int posIdx = 0;
  int len;

public:
  RLEIterator(vector<int> &encoding)
  {
    this->encoding = encoding;
    len = encoding.size();
  }

  int next(int n)
  {
    for (; posIdx < len; posIdx += 2)
    {
      int remaining = encoding[posIdx] - exhausted;
      if (remaining - n < 0)
      {
        n -= remaining;
        exhausted = 0;
      }
      else
      {
        exhausted += n;
        return encoding[posIdx + 1];
      }
    }
    return -1;
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

// TLE || since we cannot actually decode this array we need to make our approach a bit more unique
class RLEIterator
{
private:
  int pos = 0;
  vector<int> decoded;
  int len = 0;

public:
  RLEIterator(vector<int> &encoding)
  {
    for (int i = 0; i < encoding.size(); i += 2)
    {
      int n = encoding[i];
      int num = encoding[i + 1];

      for (int i = 0; i < n; i++)
        decoded.push_back(num);
    }
    len = decoded.size();
  }

  int next(int n)
  {
    pos = pos + n;

    if (pos >= len)
      return -1;
    else
      return decoded[pos];
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */