#include <iostream>
#include <vector>

using namespace std;

/*

arr1 = [1, 2, 3, 5, 6, 7],
arr2 = [3, 6, 7, 8, 20]


common elemnts == 3, 6, 7


Method 1 : Brute force way

         |
arr1 =  [1, 2, 3, 5, 6, 7],


pick every element in arr1  ->

search el picked in array2

result = [1]

TC: O(n*m)   SC: O(min(N,M))


Method 2: using Binary Search


arr1 = [1, 2, 3, 5, 6, 7],
        |

if we do Binary Search on arr2 -> we can find out if given element is present in log(M)

TC: nlogM


Method 3 : Using Two Pointers

while(i < n && j < m)

                      |
arr1 = [1, 2, 3, 5, 6, 7],

                 |
arr2 = [3, 6, 7, 8, 20]


result = [3, 6, 7]

TC: O(N+M)  SC: min(N.m)


O(N+M)  -->   Nlog(M)  // base = 2

 M ≈ N   ==


 n ~ m = 10^5

 1. operations ~ 2.10^5
 2. operations ~ 10^5*log(2)*5

M ≫ N  :: in this case method 2 would perform better than method 1
*/

vector<int> findDuplicates(const vector<int> &arr1, const vector<int> &arr2)
{
  int n = arr1.size(), m = arr2.size();
  int i = 0, j = 0;

  vector<int> commonNumbers;

  while (i < n && j < m)
  {

    if (arr1[i] < arr2[j])
    {
      i++;
    }
    else if (arr1[i] > arr2[j])
    {
      j++;
    }
    else
    {
      // arr1[i] == arr2[j]
      commonNumbers.push_back(arr1[i]); // arr2[j]
      i++, j++;
    }
  }
  return commonNumbers;
}

int main()
{
  return 0;
}