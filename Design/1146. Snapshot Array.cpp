/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
  vector<map<int, int>> cache;
  int snap_id = 0;
  SnapshotArray(int length)
  {
    cache.assign(length, {{0, 0}});
  }

  void set(int index, int val)
  {
    cache[index][snap_id] = val;
  }

  int snap()
  {
    return snap_id++;
  }

  int get(int index, int snap_id)
  {
    auto it = cache[index].upper_bound(snap_id);
    it--;
    return it->second;
  }
};