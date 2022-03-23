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

[2,3,1,1,4]


 X    -      -
[2,   3    , 1,   1  , 4]
 |

  i;ll explore all the position I can go to from i = 1
{1,2,3,4}
queue ({0})


 Sum(n_i*steps(n_i))

O(N)  // we can use some trick i.e use a visited array to prevent from looking through indicies that are already in our queue

*/

bool canJump(vector<int> &jumps)
{
  int n = jumps.size();
  vector<bool> visited(n, false);

  queue<int> q({0});
  visited[0] = true;

  while (q.empty() == false)
  {
    int curr_idx = q.front();

    for (int i = 1; i < jumps[curr_idx]; i++)
    {

      if (curr_idx + i == n - 1)
        return true;

      if (visited[curr_idx + i] == false)
      {
        q.push(i);
        visited[i] = true;
      }
    }
  }

  return false;
}

void backtrack(vector<vector<int>> &combinations, unordered_set<int> &usedNumbers, int k, int n)
{
  if (k == 0 && n == 0) //
  {
    combinations.push_back(vector<int>(usedNumbers.begin(), usedNumbers.end()));
    return;
  }
  if ((k == 0 && n != 0) || n < 0)
    return;

  for (int num = 1; num <= 9; num++) // set of n9 number
  {
    // we have two option -- take this nummber or skip this number
    if (usedNumbers.find(num) == usedNumbers.end())
    {
      usedNumbers.insert({num}); // we chose this number
      // now we will recursively call this function again

      backtrack(combinations, usedNumbers, k - 1, n - num); //

      usedNumbers.erase(num); // we are removing the number we chose
    }
    return;
  }
}

vector<vector<int>> getCombinations(int k, int n)
{
  vector<vector<int>> combinations;

  unordered_set<int> usedNumbers; // {9}

  backtrack(combinations, usedNumbers, k, n); // recursively looking through our search space

  return combinations;
}

/*
Input: k = 3, n = 7
Output: [[1,2,4]]


Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]

is repetion of number allowed

- unique numbers

all the combination of k numbers that would sum upto n

1 2 6 = 9

number are from 1 - 9

we have to exhaustively search the entire search space


k = 3   n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]



k=1      {1,....9}  9 option    -- 7 select
        /
    {8 option}                         |

1<= k <= 9

                       N
if we have k steps -> 9.8.7

TC : (9Ck)

SC: that depends on our result

if value = 9

9 - 1 - 2 - 6 = > 0


*/

/*
 *
 * k = 3   n = 7
 *
 *
 *  backtrack(3,7)
 *    |
 *     backtrack(2, 6)  : usedNumber {1}
 *             |
 *           backtrack(1, 4) : usedNumber{1,2}
 *                  |
 *                backtrack(0, 1)  userNumber{1,2,3}
 *                   |
 * combinations {}
 * usedNumber {}
 *
 *
 *
 * listOfNumber -> {,2,3,4,5,6,7,8,9}
 *                  |------------|
 * */

// O(k) + O(N)  ; where N = choices of number we can have in our combination

void backtrack(vector<vector<int>> &combinations, set<int> &nums, int k, int n)
{
  if (k == 0 && n == 0) //
  {
    combinations.push_back(vector<int>(nums.begin(), nums.end()));
    return;
  }
  if ((k == 0 && n != 0) || n < 0)
    return;

  for (int num : nums) // set of n9 number
  {
    // we have two option -- take this nummber or skip this number
    nums.erase(num); // we chose this number
    // now we will recursively call this function again
    backtrack(combinations, nums, k - 1, n - num); //
    nums.insert(num);                              // we are removing the number we chose
    return;
  }
}

vector<vector<int>> getCombinations(int k, int n)
{
  vector<vector<int>> combinations;

  set<int> nums; // {9}
  int N = 9;
  for (int i = 1; i <= N; i++) // allocate O(N)
    nums.insert(i);

  backtack(result, nums, k, n); // recursively looking through our search space

  return combinations;
}
