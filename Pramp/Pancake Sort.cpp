/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

flip(arr, k) =>
       -------
arr = [1, 5 , 4 ,3 , 2, 1 ]

[1, 5 , 4 ,3 , 2, 1 ]  =>   doing some operations

=> [....    5] =>  [.....] + [5]

Observation
1. start fixing largest elements from the back
2. then continue doing that for n-1 element

|------->   -|
[1, 5 ,4 ,3, 6,  0]
|------------|

[6, 3 ,4 ,5 ,1, 0]
-----------------

6, ,5,  4 ....

[]

k=3       |
[0, 1 ,5 ,4 ,3 ,6]
--------------

 |------
[6, 1 ,5 ,4 ,3 ,6]


*/

// Time Complexity = O(n^2)
// Space complexity = O(1)

#include <bits/stdc++.h>
using namespace std;

void flip(vector<int> &arr, int k)
{
  reverse(arr.begin(), arr.begin() + k);
}

int findMaxIdx(vector<int> &arr, int lastIdx)
{
  return (max_element(arr.begin(), arr.begin() + lastIdx) - arr.begin());
}

vector<int> pancakeSort(const vector<int> &arr_)
{
  vector<int> arr = arr_;
  int n = arr.size();

  for (int lastIdx = n; lastIdx > 0; lastIdx--)
  {
    int idx = findMaxIdx(arr, lastIdx);
    flip(arr, idx + 1);
    flip(arr, lastIdx);
  }

  return arr;
}