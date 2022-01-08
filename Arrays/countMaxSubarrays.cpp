
/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Given an array A of integers and an integer k, what is the number of valid subarrays of A?
// A subarray is valid if the difference between the maximum element and the minimum element is bounded by k.

/*



[2,,,4] can we figure out max and min ele in O(1)

[1,5,3,1,6,2,3]  k = 4

1 5 3 =>
  5 3 1


 X
[1, 5, 3, 1]

   X X X X
[1,5,3,1,6,2,3]  k = 4
 X

in this case we take a element and check all the elemets to the right until we have an invalid condition

for(int i=0; i<N; ++i) {
  max = A[i];
  min = A[i];
  for(int j=i; j<N; ++j) {
    the TC: O(N^3) -> O(N^2)
    // maintain max and min and evaluate against k.
    // break
  }
}

max => [1, 3, 5]


for a given subarray in A -> diff(MaxEL - minEl <= k )

N(N-1)/2

Method 1: Enumeration
enumerate all the possible subarray ->
once you enumerate the subarray we check if max - min <= k
TC: O(N^3) SC: O(1)

   X     X
[1,2,3,4,5,6]

can we decrease the TC

multiset<int>


         lr
 --------|
[1,5,3,1,6,2,3]  k = 4
 X

 TC: O(N*log(N))
 SC: O(N)


max -> O(1)
min -> O(1)

erase/insert -> O(logN) => O(N)if tree is unbalenced <>

have two pointers left and right and have a sorted container which could retrive max/min in O(1) time

we keep increasing the range until we reach a condtion where the max- min is not in bounds

max -> 5,3, 1
min -> 1,3 5


[1,2,3,4]
 [1] [2] [3] [4]     4
 [1,2]  [2,3] [3,4]  3
 [1,2,3] [2,3,4]     2
 [1,2,3,4]           1

   sum of n natural number -> N(N+1)/2

N-> [1]
n-1 -> [2]
n-3 -> [4]

1 -> [N]

sum of n natural numebrs

-------
1,2,3,4 5
  -------

   l
   |
[1,5,3,6,2,3]  k = 4
           |
           r

   set = [2,3,3,5,6]

   */

int countValidSubarrays(vector<int> &nums, int k)
{
  int count = 0;

  int l = 0, r = 1, n = nums.size();

  multiset<int> pq;
  pq.insert(nums[0]);

  while (r < n)
  {
    int minEL = *pq.begin();
    int maxEl = *pq.rbegin();

    if (maxEl - minEl > k)
    {
      count = r - l - 1;
      pq.erase(pq.find(nums[l++])); // O(log(N) + log(N))
    }
    else
    {
      pq.insert(nums[r++]);
    }
  }

  // have some extra addition here

  return count;
}
