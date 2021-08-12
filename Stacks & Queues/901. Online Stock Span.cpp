//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
  stack<pair<int, int>> s;

public:
  StockSpanner() {}
  int next(int price)
  {
    int result = 1;
    // 100 - 80 - 60 - 70 - 60 - 75- 85
    while (!s.empty() && s.top().first <= price)
    {
      result += s.top().second;
      s.pop();
    }
    s.push({price, result});
    return result;
  }
};
