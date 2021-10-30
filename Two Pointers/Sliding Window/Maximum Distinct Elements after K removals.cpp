/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
Recently it was decided that it is necessary to free R consecutive shelves.
Shelves cannot be reordered. What is the maximum number of types of items
which still can be stored in the storeroom after freeing R consecutive shelves?

**Examples:**

Sample 1:

Input: A = [2, 1, 2, 3, 2, 2], R = 3

Output: 2

Explanation: If we free shelves 2, 3 and 4 (shelves are numbered from 0)*

*/
class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    int n = arr.size(), count = 0;
    unordered_map<int, int> freq;
    if (n - k <= 0)
      return 0;

    // [5 5] 4
    for (int i = 0; i < n - k; i++)
    {
      freq[arr[i]]++;
      count += ((freq[arr[i]] == 1) ? 1 : 0);
    }
    int delta = n - k, result = count;
    for (int i = n - k; i < n; i++)
    {
      int remove = arr[i - delta];
      int add = arr[i];

      freq[remove]--;
      freq[add]++;

      if (freq[remove] == 0)
        count--;
      if (freq[add] == 1)
        count++;

      result = min(result, count);
    }

    return result;
  }
};