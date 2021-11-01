//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Netflix Google question

/*
Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.

void set(String key, String value, int timestamp)
- Stores the key key with the value value at the given time timestamp.

String get(String key, int timestamp)
- Returns a value such that set was called previously, with timestamp_prev <= timestamp.
- If there are multiple such values, it returns the value associated with the largest timestamp_prev.
- If there are no values, it returns "".

*/

class TimeMap
{
public:
  unordered_map<string, vector<pair<int, string>>> cache;
  TimeMap()
  {
  }

  void set(string key, string value, int timestamp)
  {
    cache[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp)
  {
    if (cache.find(key) == cache.end())
      return "";

    vector<pair<int, string>> timestamps = cache[key];

    int n = timestamps.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
      int mid = unsigned(l + r) >> 1;

      if (timestamps[mid].first < timestamp)
        l = mid + 1;
      else
        r = mid;
    }

    return l == 0 ? "" : timestamps[l - 1].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */