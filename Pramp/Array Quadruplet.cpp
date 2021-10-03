#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time Complexity -> O(n^3)
// Space Complexity -> O(1)

vector<int> findArrayQuadruplet(const vector<int> &brr, int s)
{
  vector<int> arr = brr;
  int n = arr.size();

  sort(arr.begin(), arr.end()); // for us to do the bi-direction sweep

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int l = j + 1, r = n - 1;

      while (l < r)
      {
        int curr_sum = arr[i] + arr[j] + arr[l] + arr[r];

        if (curr_sum < s)
          l++;
        else if (curr_sum > s)
          r--;
        else
          return vector<int>{arr[i], arr[j], arr[l], arr[r]};
      }
    }
  }
  return {};
}

int main()
{
  return 0;
}

/*
Brute Force O(n^4)
find all quadruplets from the array


Sorting O(n^3) 

arr  =[2, 7, 4, 0, 9, 5, 1, 3]  s= 20
  
  
  9 7 4 0
  
  1.  [0 4 7 9]  return in sorted order
  2. 

  3. make sure that the quadruplet you find is the first one
  3. sort the array
  
  
  
arr  =[2, 7, 4, 0, 9, 5, 1, 3]

1. sort the array


0, 1 ,2, 3 ,4 ,5, 7 , 9     [target = 20]


for(i:0 -> n)
  for (j:i+1 -> n)
    {
      l = j + 1 
      r = n -1
     while(l< r)
      sum = arr[i] + arr[j] + arr[l] + arr[r]  {--r}
    
    }
  
  arr[i] + arr[j] + [2 other indices which we will find]  = target


  
  */