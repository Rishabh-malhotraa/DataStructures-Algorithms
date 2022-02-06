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
private:
  int startAt, moveCost, pushCost;
  int calculate(string time)
  {
    if (time.size() > 4)
      return INT_MAX;
    string s;
    int i = 0;
    while (time[i] == '0')
      i++;

    time = time.substr(i);

    char prev = '0' + startAt;
    int cost = 0;
    for (char ch : time)
    {
      if (prev == ch)
      {
        cost += pushCost;
      }
      else
      {
        prev = ch;
        cost += pushCost + moveCost;
      }
    }
    // cout << time << " " << cost << endl;
    return cost;
  }

public:
  int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
  {
    this->startAt = startAt;
    this->moveCost = moveCost;
    this->pushCost = pushCost;

    int minutes = targetSeconds / 60;
    int seconds = targetSeconds % 60;

    int result = INT_MAX;

    string zeroSec = "";
    if (seconds >= 0 && seconds <= 9)
      zeroSec = string(1, '0') + to_string(seconds);
    else
      zeroSec = to_string(seconds);

    string s1 = to_string(minutes) + zeroSec;

    string s2 = (seconds + 60 < 100 && minutes != 0) ? to_string(minutes - 1) + to_string(seconds + 60) : s1;
    result = min(calculate(s1), calculate(s2));
    return result;
  }
};