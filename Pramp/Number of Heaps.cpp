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

[0,1,2,3,4]

a[3] = a[n/2]
a[4] = a[(n-1)/2]

if i is odd ->   i   /2 parent
if i is even -> (i-1)/2

         0
        / \
       1   2
     /  \
    3   4
*/

int getParent(int idx)
{
  return (idx % 2) ? (idx - 1) / 2 : idx / 2;
}

void backtrack(vector<int> &heap, vector<pair<int, bool>> &candidates, int &idx, int &count)
{
  if (idx == heap.size())
  {
    count++;
    return;
  }

  for (auto &[value, visited] : candidates)
  {
    int parentIdx = getParent(idx);

    if (visited == false && heap[parentIdx] > value)
    {
      visited = true;
      heap[idx] = value;
      dfs(heap, candidates, idx + 1, count);
      heap[idx] = 0;
      visited = false;
    }
  }
  return;
}

int Solution::solve(int A)
{
  vector<int> heap(A, 0);
  heap[0] = A;

  vector<pair<int, bool>> candidates;
  for (int i = 1; i < A; i++)
    candidates.push_back({i, false});

  int idx = 1, count = 0;
  backtrack(heap, candidates, idx, count);

  return count;
}

/*
10

   1        - 0
  2         - 1
 4          - 2
3           - 3


log(10) -> 3

2^(h) - 1 = 10
2^h = 8
h = 3

7
*/

class CountHeaps
{
private:
  int mod = 1e9 + 7;

  int NumOfNodesOnLeft(int n)
  {
    int h = log2(n);
    int x = ((pow(2, h - 1)) - 1);
    int y = min(pow(2, h - 1), (n - pow(2, h) - 1));
    return x + y;
    /*

               *
           *       *
        *    *    *  *
       * *  * *

     n = 11  x = 3 || y = 4
    */
  }

  int Combination(int n, int r)
  {
    if (r > n - r)
      r = n - r; // because C(n, r) == C(n, n - r)
    int result = 1;
    int i;

    for (i = 1; i <= r; i++)
      result *= n - r + i, result /= i;

    return result;
  }

public:
  int numberOfHeaps(int n)
  {
    if (n == 1)
      return 1;

    int left = NumOfNodesOnLeft(n);
    int right = n - 1 - left;

    long long result = (((Combination(n - 1, left) * numberOfHeaps(left)) % mod) * numberOfHeadps(right)) % mod;

    return result;
  }
};

/*
   *
  / \
 *


Problem Description

Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.

Find the number of distinct Max Heap can be made from A distinct integers.

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
Every node is greater than all its children.
NOTE: If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.



Problem Constraints
1 <= A <= 100



Input Format
First and only argument is an inetegr A.



Output Format
Return an integer denoting the number of distinct Max Heap.



Example Input
Input 1:

 A = 4
Input 2:

 A = 10


Example Output
Output 1:

 3
Output 2:

 3360


Example Explanation


10 ->
    1
   2
  4
 3

Explanation 1:

 Let us take 1, 2, 3, 4 as our 4 distinct integers
 Following are the 3 possible max heaps from these 4 numbers :

      4           4                     4
    /  \         / \                   / \
   3    2   ,   2   3      and        3   1
  /            /                     /
 1            1                     2


       4
     /    \
{1,2,3}

    4
  /  \
 {3} {1,2}


we have to fill n spots -> 1 _ _ _

      4           4                     4
    /  \         / \                   / \
   1    2 ,     2   3      and        3   1
  /            /                     /
 3            1                     2


4 3 2 1
3!


PnC ->


Explanation 2:
 A  = 10
 Number of distinct heaps possible with 10 distinct integers = 3360.


Intuition:

1. Derive some relation between subresult numberOfHeap[a=4] -> numberOfHeaps[a=5]
2. Strucutre has to be same
3. The root value is fixed


4. Rather than finding an PnC solution for this problem
   Exgaustively going through the search space
   and then adding those answers which are valid



a = 1 ->  1
a = 2 ->  1
a = 3 ->  2
a = 4
4 ----
  1 2 3
  3 2 1

      4           4                     4
    /  \         / \                   / \
   1    2 ,     2   3      and        3   1
  /            /                     /
 3            1                     2


5 -> {1,2,3,4,5}

        [5]     [5]
       /  \     / \
      3    4   4   3

Are the numbers in left and right subtree independent of each other?
*/