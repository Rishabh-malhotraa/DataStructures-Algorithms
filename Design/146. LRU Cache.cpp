//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
  int capacity;
  unordered_map<int, int> keys;
  unordered_map<int, list<int>::iterator> pos;
  list<int> cache;

  void use(int key)
  {
    // if you have the key already present then remove it
    if (keys.find(key) != keys.end())
    {
      cache.erase(pos[key]);
    }
    else if (cache.size() >= capacity)
    {
      pos.erase(cache.back());
      keys.erase(cache.back());
      cache.pop_back();
    }

    cache.push_front(key);
    pos[key] = cache.begin();
  }

public:
  LRUCache(int capacity)
  {
    this->capacity = capacity;
  }

  int get(int key)
  {
    int result = -1;
    if (keys.find(key) != keys.end())
    {
      use(key);
      result = keys[key];
    }
    return result;
  }

  void put(int key, int value)
  {
    use(key);
    keys[key] = value;
  }
};
