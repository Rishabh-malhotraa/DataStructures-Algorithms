// hello.cpp
#include <bits/stdc++.h>
#include <optional>
using namespace std;


// this is being more efficient
class CacheIII
{
private:
  unordered_map<string, string> checkpoint;
  stack<unordered_map<string, pair<string, bool>>> transactionStore;
  unordered_map<string, string> deletedKeys;
  bool transactionActive;
public:
  CacheIII() {}

  string get(string key)
  {
    if()

    if (transactionStore.find(key) == transactionStore.end() && transactionStore.find(key) == transactionStore.end())
    {
      return "NOT_FOUND";
    }

    bool keyInStore = transactionStore.find(key) != transactionStore.end();

    return keyInStore ? transactionStore[key] : checkpoint[key];
  }

  void put(string key, string value)
  {
    transactionStore.top().[key] = value;
  }

  void del(string key, string value)
  {
    bool keyInCheckpoint = transactionStore.find(key) != transactionStore.end();

    if (keyInCheckpoint) {
      deletedKeys[key] = checkpoint[key];
    }

    transactionStore.erase(key);
    checkpoint.erase(key);
  }

  void beginTransaction()
  {
    if (checkpoint.size() > 0)
    {
      cout << "Previous Transaction is still ongoing" << endl;
    }
    transactionActive = true;
    return;
  }

  void rollback()
  {
    for (auto [key, value] : deletedKeys) {
      checkpoint[key] = value;
    }
  }

  void commit() {
    // apply changes - merge two unordered Map
    for (auto [key, value] : transactionStore) {
      checkpoint[key] = value;
    }
  }
};













// this is being more efficient
class CacheII
{
private:
  unordered_map<string, string> checkpoint;
  unordered_map<string, string> store;
  unordered_map<string, string> deletedKeys;
  bool transactionActive;
public:
  CacheII() {}

  string get(string key)
  {
    if (store.find(key) == store.end() && store.find(key) == store.end())
    {
      return "NOT_FOUND";
    }

    bool keyInStore = store.find(key) != store.end();

    return keyInStore ? store[key] : checkpoint[key];
  }

  void put(string key, string value)
  {
    store[key] = value;
  }

  void del(string key, string value)
  {
    bool keyInCheckpoint = store.find(key) != store.end();

    if (keyInCheckpoint) {
      deletedKeys[key] = checkpoint[key];
    }

    store.erase(key);
    checkpoint.erase(key);
  }

  void beginTransaction()
  {
    if (checkpoint.size() > 0)
    {
      cout << "Previous Transaction is still ongoing" << endl;
    }
    transactionActive = true;
    return;
  }

  void rollback()
  {
    for (auto [key, value] : deletedKeys) {
      checkpoint[key] = value;
    }
  }

  void commit() {
    // apply changes - merge two unordered Map
    for (auto [key, value] : store) {
      checkpoint[key] = value;
    }
  }
};






class Cache
{
private:
  unordered_map<string, string> store;
  stack<unordered_map<string, string>> checkpoint;

public:
  Cache() {}

  string get(string key)
  {
    if (store.find(key) == store.end())
    {
      return "";
    }
    return store[key];
  }

  void put(string key, string value)
  {
    store[key] = value;
  }

  void del(string key, string value)
  {
    store.erase(key);
  }

  void beginTransaction()
  {
    if (checkpoint.size() > 0)
    {
      cout << "Previous Transaction is still ongoing" << endl;
    }

    checkpoint.push(store);
  }

  void rollback()
  {
    auto last_checkpoint = checkpoint.top();
    checkpoint.pop();
    store = last_checkpoint;
  }
  void commit()
  {
    checkpoint.pop();
  }
};

int main()
{
  Cache cache;

  cache.put("1", "2");
  assert(cache.get("1") == "2");

  cache.beginTransaction();

  cache.put("2", "3");
  cache.put("4", "5");
  cache.put("6", "8");

  cache.rollback();

  cout << cache.get("2") << endl;
  cout << cache.get("1") << endl;

  cout
    << "Hello, World!" << endl;
  return 0;
}