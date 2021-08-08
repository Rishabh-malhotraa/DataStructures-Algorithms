//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Simple Version w/o collision handling or anything
class MyHashMap
{
public:
  int data[1000001];

  MyHashMap()
  {
    fill(data, data + 1000000, -1);
  }

  void put(int key, int val)
  {
    data[key] = val;
  }

  int get(int key)
  {
    return data[key];
  }

  void remove(int key)
  {
    data[key] = -1;
  }
};

struct Node
{
public:
  int key, val;
  Node *next;
  Node(int k, int v, Node *n)
  {
    key = k;
    val = v;
    next = n;
  }
};
class MyHashMapWithCollisions
{
public:
  const static int size = 19997;
  const static int mult = 12582917;
  Node *data[size];
  int hash(int key)
  {
    return (int)((long)key * mult % size);
  }
  void put(int key, int val)
  {
    remove(key);
    int h = hash(key);
    Node *node = new Node(key, val, data[h]);
    data[h] = node;
  }
  int get(int key)
  {
    int h = hash(key);
    Node *node = data[h];
    for (; node != NULL; node = node->next)
      if (node->key == key)
        return node->val;
    return -1;
  }
  void remove(int key)
  {
    int h = hash(key);
    Node *node = data[h];
    if (node == NULL)
      return;
    if (node->key == key)
      data[h] = node->next;
    else
      for (; node->next != NULL; node = node->next)
        if (node->next->key == key)
        {
          node->next = node->next->next;
          return;
        }
  }
};