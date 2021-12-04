/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Logger
{
public:
  unordered_map<string, int> cache;
  Logger()
  {
  }

  bool shouldPrintMessage(int timestamp, string message)
  {
    if (cache.find(message) == cache.end())
    {
      cache[message] = timestamp;
      return true;
    }

    if (cache[message] + 10 <= timestamp)
    {
      cache[message] = timestamp;
      return true;
    }

    return false;
  }
};