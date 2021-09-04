/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class LockingTree
{
private:
  vector<int> parent;
  unordered_map<int, vector<int>> child;

  vector<int> locked;

public:
  LockingTree(vector<int> &parent)
  {
    this->parent = parent;
    child[0] = vector<int>{};
    locked.assign(parent.size(), -1);
    for (int i = 0; i < parent.size(); i++)
    {
      locked[i] = -1;
      if (parent[i] != -1)
        child[parent[i]].push_back(i);
    }
  }

  bool lock(int num, int user)
  {
    bool result = false;
    if (locked[num] == -1)
    {
      locked[num] = user;
      result = true;
    }
    return result;
  }

  bool unlock(int num, int user)
  {
    bool result = false;

    if (locked[num] == user)
    {
      locked[num] = -1;
      result = true;
    }
    return result;
  }

  bool upgrade(int num, int user)
  {
    bool result = false;
    int node = num;

    // check if node is locked
    if (locked[node] != -1)
      return false;

    // checking ancestors
    while (parent[node] != -1)
    {

      if (locked[parent[node]] != -1)
        return false;
      node = parent[node];
    }

    // check descendant
    queue<int> q;
    q.push(num);
    bool isAnyLocked = false;
    vector<int> temp = locked;
    temp[num] = user;

    while (!q.empty())
    {
      int curr = q.front();
      q.pop();

      for (int &neighbours : child[curr])
      {
        if (locked[neighbours] != -1)
          isAnyLocked = true;
        q.push(neighbours);
        temp[neighbours] = -1;
      }
    }
    if (isAnyLocked == false)
      return false;

    locked = temp;

    return true;
  }
};