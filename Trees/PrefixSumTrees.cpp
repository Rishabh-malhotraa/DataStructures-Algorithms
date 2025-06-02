#include <iostream>
using namespace std;

// Get sum of all elements in binary search tree which are in range [low, high] inclusive.
//              6 
//            /   \
//           4     8
//          / \   / \
//         3   5 7   9
//        /
//       2

// Input: [2, 5] => 14
// Input: [8, 9] => 17
// Input: [4, 6] => 15
// Input: [3, 10] => 42
// To execute C++, please define "int main()"

/*
Approach 1:
traverse through teh binary tree
O(N) O(h)

Apprach 2: Using properties of a binary search tree


 NOde -> the value of node is in the range -> I'll add this to my sum

  If the valude of the give node is < low : no need to go to search the left subtree
 node->val > low
node->val <

TC: O(N) : in the worst case
SC: O(h) :


    /*
      range -> [3, 7]

                  the idx of lower_bound-> of low
                  the idx of upper_bound ->high - 1

                  lower_bound(array, low)
                  upper_bound(array, high) - 1;

                     [3, 7]

                        X        X
                   [2 , 3 , 5 ,  7,   9]
     prefix Sum ->  [2,  5,  10, 17,  26] :

    17 - 5 = 12


    8 + 7 ->
    */

    //              6 
    //            /   \
    //           4     8
    //          / \   / \
    //         3   5 7   9
    //        /
    //       2



    // Input: [2, 5] => 14
    // Input: [8, 9] => 17
    /*

    low = 2  high = 5
    Start   6     sum = 0
           4      sum = 4
         3        sum = 4 + 3
       2          sum + 4 + 3 + 2
           5      sum = 4 + 3 + 2 + 5 => 14

    */


class Node {
  int value;
  Node* left;
  Node* right;
};

int getRangeSum(Node* root, int low, int high) {
  if (root == NULL) {
    return 0;
  }
  int sum = 0;

  if (root->val >= low && root->val <= high) {
    sum += root->val;
  }

  /*
    dfs(node(6))
      dfs(node(4))
  */

  // 6 > high [5
  if (root->val > high) {
    sum += getRangeSum(root->left, low, high);
  }

  if ((root->val < low)) {
    sum += getRangeSum(root->right, low, high);
  }

  return sum;
}

int main() {


  return 0;
}

/*
For example:
Input:
{[1,2], [3,9]}
{[4,6], [8,10], [11,12]}

Output should be:
{[1,2], [3,10], [11,12]}

0   1   2   3   4   5   6   7   8   9  10  11  12
    [---]   [-----------------------]
                [-------]       [------]   [----]
    [---]   [--------------------------]   [----]


Approach : Brute Force

concatinate the list -> sort

TC: ON+Mlog(n+M) + TC: OF MERGING THE LIST
merging


RESULT []

i1
LIST 1  []

i2
LIST 2


TC: O(N+M)
SC: O(N+M) WC





0   1   2   3   4   5   6   7   8   9  10  11  12
    [---]   [-----------------------]
                [-------]       [------]   [----]
    [---]   [--------------------------]   [----]


e1 [INT_MAX, INT_MAX]
e2 [4, 6]

   4----6
3----------9

interValToMerge = [4, 6]

result [[1,2], [3, 9]]

i1 =1  i2 = 0

*/

vector<pair<int, int>> mergeLists(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
  vector<pair<int, int>> result;
  int i1 = 0, i2 = 0, n1 = a.size(), n2 = b.size();

  while (i1 < n1 || i2 < n2) {

    pair<int, int> e1 = (i1 < n1) : a[i1] : {INT_MAX, INT_MAX};
    pair<int, int> e2 = (i2 < n2) : b[i2] : {INT_MAX, INT_MAX};

    pair <int, int> intervalToMerge = (e1.first < e2.first) ? e1 : e2;
    (e1.first < e2.first) ? i1++ : i2++;

    pair<int, int>& top = (!result.empty()) ? result.back() : intervalToMerge;
    if (intervalToMerge.first > top.second) {
      result.push_back(intervalToMerge);
    }
    else {
      top.second = max(top.second, intervalToMerge.second);
    }



    /*
       1------5
          2-3
        What I want to check is
        the end value of my top >
    */


  }
  return result;
}

