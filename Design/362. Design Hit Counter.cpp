/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class HitCounter
{
  list<int> timeStream;
  int counter = 0;

public:
  HitCounter()
  {
  }

  void hit(int timestamp)
  {
    timeStream.push_back(timestamp);
    counter++;
  }

  int getHits(int timestamp)
  {
    int startTime = (timestamp - 300 < 0) ? 0 : timestamp - 300;

    while (!timeStream.empty() && timeStream.front() <= startTime)
    {
      timeStream.pop_front();
      counter--;
    }
    return counter;
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */