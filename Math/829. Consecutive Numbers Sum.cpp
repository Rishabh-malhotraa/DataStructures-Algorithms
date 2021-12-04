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

1. Find Upper Bound for what is the max n possible

X = k*n + n(n+1)/2

15 = 4 + 5 + 6
     1   2   3
     3   3   3 

k = (X/n) - (n+1)/2    -    (i)

K ∈ I 
K > 0


(2*X + 1/4)  >= (n + 1/2)^2


n <= sqrt(2*X + 0.25) - 0.5

N > n is not possible  
*/

class Solution
{
public:
  int consecutiveNumbersSum(int X)
  {
    int upper_bound = sqrt(2.0 * X + 0.25) - 0.5, count = 0;

    // the <"=" sign is important for multiples , eg : ub = 3
    for (int n = 1; n <= upper_bound; n++)
    {
      int curr_sum = (n * (n + 1)) / 2;
      if ((X - curr_sum) % n == 0)
        count++;
    }
    return count;
  }
};