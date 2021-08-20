#include <bits/stdc++.h>
using namespace std;

// PRAMP SESSION

/*
                |
  arr =  [1, 10, 0, 2, 8, 3, 0, 0, 6, 4, 0, 5, 7, 0]
result : [1, 10, 2, 8, 3, 6, 4, 5, 7, 0, 0, 0, 0, 0]

Brute force solution : O(n^2)

for(int i =0 ; i< n ; i++){
  for(int j = i+1 ; j< n ; j++){
  
  }
}
---------------------------------------------------------


Method 2 : 
  - Count the number of zeros in the array
  - arr2 -> traverse arr and insert elemetns which are not zero
  - insert the number of zeros in the end
  
  Time complexity : O(n)
  Space Complexity: O(N)

---------------------------------------------------------

Method 3 : Constant Space &  TC: O(N)

[1, 10, 2, 0, 8, 3, 0, 0, 6, 4, 0, 5, 7, 0]
                        | swa
  1 10 2 8 3 6
  (i - count)

1 10 2 0 8 3 0 0 6 4 0 5 7 0
      |
  1. 1 10 2 0 8 3 0 0 6 4 0 5 7 0
  2. 1 10 2 0 8 3 0 0 6 4 0 5 7 0 
  3. 1 10 2 0 8 3 0 0 6 4 0 5 7 0
  4. 1 10 2 0 8 3 0 0 6 4 0 5 7 0
  
  5. 1 10 2 8 3 6 4 5 7 0 0 0 0 0
  
 */

vector<int> moveZerosToEnd(const vector<int> &brr)
{
  vector<int> arr = brr;
  int count = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
      count++;
    else
      swap(arr[i], arr[i - count]);
  }

  return arr;
}
