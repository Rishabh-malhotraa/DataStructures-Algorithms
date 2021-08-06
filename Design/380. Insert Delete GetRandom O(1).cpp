//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// HASHMAP x Arrays | HARD

class RandomizedSet
{
public:
  vector<int> nums;
  unordered_map<int, int> lookup; // value to idx
  /** Initialize your data structure here. */
  RandomizedSet()
  {
  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val)
  {
    if (lookup.find(val) != lookup.end())
      return false;

    nums.push_back(val);
    lookup[val] = nums.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val)
  {
    if (lookup.find(val) == lookup.end())
      return false;

    int idx = lookup[val];
    int end = nums.size() - 1;
    int end_el = nums[end];

    lookup[end_el] = idx;

    swap(nums[idx], nums[end]);

    nums.pop_back();
    lookup.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom()
  {
    int n = nums.size();
    int random_idx = rand() % n;
    return nums[random_idx];
  }
};
