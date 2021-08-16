//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class getDayFromDate
{
private:
  bool isLeap(int year)
  {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
  }

  bool isValidDate(int d, int m, int y)
  {
    if (y < 0)
      return false;
    if (m < 1 || m > 12)
      return false;
    if (d < 1 || d > 31)
      return false;

    if (m == 2)
      if (isLeap(y))
        return (d <= 29);
      else
        return (d <= 28);

    if (m == 4 || m == 6 || m == 9 || m == 11)
      return (d <= 30);

    return true;
  }

public:
  int dayofweek(int d, int m, int y)
  {
    if (isValidDate(d, m, y) == false)
      return -1;

    vector<int> t = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
  }
};