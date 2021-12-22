/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

using namespace std;

class Solution
{
public:
  int depthSum(vector<NestedInteger> nestedList, int depth = 1)
  {
    int result = 0, n = nestedList.size();
    for (int i = 0; i < n; i++)
    {
      if (nestedList[i].isInteger())
        result += depth * nestedList[i].getInteger();
      else
        result += depthSum(nestedList[i].getList(), depth + 1);
    }
    return result;
  }
};
