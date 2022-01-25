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
 look you need to plant everything
 so you need to atleast spend -> accumulate(planTime) amount of time

 -> the difference here is grow time
 -> if the plant takes longer to grow its better to plant it early so it would have
    more time to grow as supposed to a plant with lower grow time
 -> The deciding factor in blooming everything in optimal time is growTime
 -> The flower with higher grow Time should be planted first
 ->

plantTime = [1,4,3], growTime = [2,3,1]


----XXX      PLANT 1
    -XX      PLANT 2
     ---X    PLANT 3
0<----->9
*/
class Solution
{
public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
  {
    vector<pair<int, int>> plants;
    int n = plantTime.size();
    for (int i = 0; i < n; i++)
      plants.push_back({growTime[i], plantTime[i]});

    sort(plants.rbegin(), plants.rend());

    int time = 0, lastWorkDay = 0;

    for (auto [grow, plant] : plants)
    {
      time = max(time, lastWorkDay + grow + plant);
      lastWorkDay += plant;
    }
    return time;
  }
};

// UNINTUITVE COD
class Solution
{
public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
  {
    vector<pair<int, int>> plants;
    int n = plantTime.size();
    for (int i = 0; i < n; i++)
      plants.push_back({growTime[i], plantTime[i]});

    sort(plants.begin(), plants.end());

    int time = 0;

    for (auto [grow, plant] : plants)
    {
      time = max(time, grow) + plant;
    }

    return time;
  }
};