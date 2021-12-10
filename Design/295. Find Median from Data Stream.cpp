/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
  priority_queue<int> low;
  priority_queue<int, vector<int>, greater<int>> high;

public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    low.push(num);
    high.push(low.top());
    low.pop();
    low.push(high.top());
    high.pop();
  }

  double findMedian()
  {
    int n = (low.size() + high.size());

    return (n % 2) ? (low.top() + high.top()) * 0.5 : low.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */