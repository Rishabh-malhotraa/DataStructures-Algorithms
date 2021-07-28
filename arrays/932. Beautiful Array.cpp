// 932. Beautiful Array - Weirdest Questions I have ever encountered
// Divide and Conqor

//! TRASH QUESTION NO CHANCE OF LEARNING ANYTHING FROM THIS

/**
 * The idea lies in diviiding the array into two parts and the creating a new array with them
 * create an odd array with prev array  => 2*el - 1
 * create an even array with prev array => 2*el
 * Only add those elements in the array whose value is < N
 * ! I Still can't wrap my head around why does this even work D:
--------------------------------------------------------------------------------------
A summary of the properties of a Beautiful Array:
I. Given a beautiful array A, the following properties holds:
(1) A' = A*c is a Beautiful array
(2) A' = A + c is a Beautiful array
(3) if A' is an array obtained by deleting some element in A, then A' is still Beautiful.

II. Given two Beautiful array A and B, whose elements are odd and even respectively,
    then concatenation array A + B is still Beautiful.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> beautifulArray(int n)
  {
    vector<int> result = {1};

    while (result.size() < n)
    {
      vector<int> temporary;
      for (int el : result)
        if (el * 2 - 1 <= n)
          temporary.push_back(2 * el - 1);
      for (int el : result)
        if (el * 2 <= n)
          temporary.push_back(2 * el);
      result = temporary;
    }
    return result;
  }
};