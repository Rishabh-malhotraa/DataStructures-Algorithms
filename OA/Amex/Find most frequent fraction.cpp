//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &X, vector<int> &Y)
{
  map<pair<long long, long long>, int> cache;
  long long n = X.size();
  for (long long i = 0; i < n; i++)
  {
    long long divisor = __gcd(X[i], Y[i]);
    long long a = X[i] / divisor;
    long long b = Y[i] / divisor;
    pair<long long, long long> p = {a, b};

    cache[p] += 1;
  }

  int result = INT_MIN;

  for (auto el : cache)
    result = max(result, el.second);

  return result;
}