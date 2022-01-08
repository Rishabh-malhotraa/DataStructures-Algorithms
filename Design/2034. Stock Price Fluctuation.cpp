/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class StockPrice
{
  multiset<int> prices;
  map<int, int> cache;

public:
  StockPrice()
  {
  }

  void update(int timestamp, int price)
  {
    if (cache.count(timestamp))
      prices.erase(prices.find(cache[timestamp]));

    cache[timestamp] = price;
    prices.insert(price);
  }

  int current()
  {
    return cache.rbegin()->second;
  }

  int maximum()
  {
    return *prices.rbegin();
  }

  int minimum()
  {
    return *prices.begin();
  }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */