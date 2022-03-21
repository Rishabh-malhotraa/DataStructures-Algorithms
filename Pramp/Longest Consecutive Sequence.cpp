/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

using namespace std;
/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109


---------------



Input: nums = [100,4,200,1,3,2] : result = [1,2,3,4]

Method 1 : Sort the array  : TC:  O(nlogn)

nums = [1,2,3,4,100,200]
          |

     [1]
   result = 1
                               value  count
   we can use a unordered_map<int,   int>

    for ( i: 1 -> n)
   {
    f

        if (arr[i] == arr[i-1] + 1){
          cont ++;
        }
        else{
          cont=1;
          ans = max(ans, cont);
        }

   }
   ans = max(ans, cont)

        if value is 1 the length of LCS = 1 for array [1]
cache = [1,1]
        [2, 1+cache[1]]



*/

class Solution
{
public:
  /*
  nums = [100,4,200,1,3,2]

  nums = [1,2,3,4,100,200]
                   |

  i = 4
  el = 2  key = 1

  maxLength = 4

  el-1  el  -- all the number to the right of el would be greater than el since the arrya is sorted

  cache = {1 : 1, 2: 2, 3:3, 4:4, 100: 1, 200 : 1 }
  */

  int longestConsecutive(vector<int> &nums)
  {
    unordered_map<int, int> cache;
    int n = nums.size();

    sort(nums.begin(), nums.end()); // this is O(nlog(N))
    int maxLength = 0;

    // we can put all the number in unorderd map first
    //

    for (int i = 0; i < n; i++)
    {
      int el = nums[i];
      int key = nums[i] - 1;
      if (cache.find(key) != cache.end())
      {
        maxLength = max(maxLength, cache[key] + 1);

        cache[el] = cache[key] + 1;
      }
      else
      {
        cache[el] = 1;
      }
    }
    return maxLength;
  }
};

class Solution
{
public:
  /*
https://www.linkedin.com/in/rishabh-malhotra-4536a418b/
cache {1,2,3,4,100,200}  // we can check if a element exist in our array in O(1) time

nums = [100,4,200,1,3,2]
                  |

o does not exist
so lets start our chain from 1

counr = 4  el = 5


 does key exist in our cache = 100 -1 =>99
  if it does exist then we skip the iteration
  if it does not exist

  X  1 2 3 4
     |


  i = 4
  el = 2  key = 1

  maxLength = 4

  el-1  el  -- all the number to the right of el would be greater than el since the arrya is sorted

  cache = {1 : 1, 2: 2, 3:3, 4:4, 100: 1, 200 : 1 }
  */

  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    unordered_set<int> cache(nums.begin(), nums.end());

    int maxLength = 0; // if our nums = []

    // we can put all the number in unorderd map first
    //
    for (int i = 0; i < n; i++)
    {
      int el = nums[i];
      int key = nums[i] - 1;
      // if there exist a smaller value we skip
      // X
      // 3 1 2 4 5 6
      // |
      // does key exist in you cache -- if it exist dont go inside this if statement
      if (cache.find(key) == cache.end())
      {
        int count = 0;
        while (cache.find(el) != cache.end()) // does 100 exist in our cache
        {
          el++;    // 101
          count++; // 1
        }
        maxLength = max(maxLength, count);
      }
    }
    return maxLength;
  }
};

//   [1,1,1,1,0],
//   [1,1,0,1,0],
//   [1,1,0,0,0],
//   [0,0,0,0,0]

//   Input: grid = [
//   [1,1,0,0,0],
//   [1,1,0,0,0],
//   [0,0,1,0,0],
//   [0,0,0,1,1]
// ]