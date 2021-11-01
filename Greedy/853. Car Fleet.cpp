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
 (1)  (6)  (3) (4) (5)
  Y    Y    X   X   X  |
 +1   +1   +0  +0  +1
*/

class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    int n = speed.size();
    vector<pair<int, double>> car(n, {0, 0});

    for (int i = 0; i < n; i++)
      car[i] = {position[i], (double)(target - position[i]) / speed[i]};

    sort(car.begin(), car.end(), greater<int>());

    double curr_time = 0.0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      if (car[i].second > curr_time)
      {
        curr_time = car[i].second;
        result++;
      }
    }
    return result;
  }
};