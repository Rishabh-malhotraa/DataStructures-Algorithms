/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int N = 26;
class TrieNode
{
public:
  bool isTerminal;
  int value;
  vector<TrieNode *> children;

  TrieNode(int value = 0)
  {
    children.assign(N, NULL);
    isTerminal = false;
    this->value = value;
  }
};

class MapSum
{
private:
  TrieNode *root;
  map<string, int> cache;

public:
  /** Initialize your data structure here. */
  MapSum()
  {
    root = new TrieNode();
  }

  void deletePrevious(string key, int value)
  {
    TrieNode *curr = root;
    for (char ch : key)
    {
      int idx = ch - 'a';
      curr = curr->children[idx];
      curr->value -= value;
    }
  }

  void
  insert(string key, int val)
  {
    if (cache.find(key) != cache.end())
      deletePrevious(key, cache[key]);

    TrieNode *curr = root;
    for (char ch : key)
    {
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        curr->children[idx] = new TrieNode(val);
      else
        curr->children[idx]->value += val;

      curr = curr->children[idx];
    }

    cache[key] = val;
  }

  int sum(string prefix)
  {
    int result = 0, idx;
    TrieNode *curr = root;
    for (char ch : prefix)
    {
      idx = ch - 'a';
      cout << curr->value << endl;
      if (curr->children[idx] == NULL)
        return 0;

      curr = curr->children[idx];
    }
    return curr->value;
  }
};