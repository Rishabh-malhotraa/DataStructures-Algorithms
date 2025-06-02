/*

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.



Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.

      ---->
num : 99735
      ----

Approach 1:

num : 2736

       X
num : 7632
            *
      7212636

 9 digit ->   O(nlogn) --- O(N)

 ============================

        X
 9987  4635  s[i] < s[i+1]

 ----|          -
 7766688885555528765


  8
*/

int getPivotIdx(string& num) {
  int pivotIdx = 0
    for (int i = 1; i < num.size(); i++) {
      if (num[i - 1] < num[i]) {
        pivotIdx = i;
        break
      }
    }
  return pivotIdx
}

string maximumSwap(string num) {
  int n = num.size();

  int pivotIdx = getPivotIdx(num);
  // if (n == 1)


  // find my max number

  int maxValue = num[pivotIdx] - '0';
  int maxIdx = pivotIdx;

  for (int i = pivotIdx; i < n; i++) {
    int currValue = num[i] - '0';
    if (currValue > maxValue) {
      maxValue = currValue
    }
    else if (currValue == maxValue) {
      maxIdx = i;
    }
  }

  // swap  

  for (int i = 0; i < pivotIdx; i++) {
    int currValue = num[i] - '0';
    if (currValue < maxValue) {
      swap(num[i], num[swapIdx]);
      break;
    }
  }

  return num;
}

/*

Minimum Number of Swaps



->
7632
                      --------------->
HASHMAP -> [value] -> [idx1, idx2, idx3]

->
7646632
 X

1:3  -> find that idx that is not equal 6:

 X
7666432   -> lb : ub  [1,3]
 X

[1-3]->

number of swap -> 3

NlogN + NlogN


 [value] -> [idx1, idx2, idx3]
           X
  [7]  -> [1 5 8] : B


  find upper_bound on the B for value [3]

  lb : ub [1,3]






  X
98518582053600   : num


  X
98886555321000   : sortedNum


minSwap = 1

1. Check if the values are equal
  - YES : increase both pointers
  - No
      - do a lb: ub of num[i] in SortedNum
      - Do an it = upper_bound(sorted.begin(), sorted.end(), rangeEnd);
      - at the end of our swaps we update our map

Test
              X
[9] -> [4]   [4]
[8] -> [1,4,6]
            X
 [4:6]
[1:3]
Do an it = upper_bound(sorted.begin(), sorted.end(), rangeEnd);
if it == sorted.begin()

*/

