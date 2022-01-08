/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class DetectSquares
{
private:
  multiset<pair<int, int>> coords;
  vector<pair<int, int>> points;

public:
  DetectSquares()
  {
  }

  void add(vector<int> point)
  {
    points.push_back({point[0], point[1]});
    coords.insert({point[0], point[1]});
  }

  int count(vector<int> point)
  {
    int x1 = point[0], y1 = point[1];
    int count = 0;
    for (auto &[x3, y3] : points)
    {
      if (x3 == x1 || abs(y3 - y1) != abs(x3 - x1))
        continue;

      count += coords.count({x1, y3}) * coords.count({x3, y1});
    }
    return count;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */