
//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
  unordered_map<int, list<int>::iterator> pos;
  unordered_map<int, int> cache;
  list<int> stream;
  int capacity;
  LRUCache(int capacity)
  {
    this->capacity = capacity;
  }

  void update(int key)
  {
    if (pos.find(key) != pos.end())
    {
      stream.erase(pos[key]);
    }
    else if (stream.size() == capacity)
    {
      pos.erase(stream.back());
      cache.erase(stream.back());
      stream.pop_back();
    }
    stream.push_front(key);
    pos[key] = stream.begin();
  }

  int get(int key)
  {
    if (cache.find(key) == cache.end())
      return -1;

    update(key);
    return cache[key];
  }

  void put(int key, int value)
  {
    cache[key] = value;
    update(key);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */