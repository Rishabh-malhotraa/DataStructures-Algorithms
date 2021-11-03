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
length = n
binary string

    X
  1
10
lineary traverse your Binarsy string
- the moment you see 1


  O(N^2)
  -> number of 1 =1 sliding window of size 2
  -> numed of 1 =2 sliding window of size 4



 count the numebr of 1(n)  = 5


  for i : 1 - > n

  sliding 2*i

    once we fix an end for prefix 1


      we will look at prefix zero and


        |      |-> end
    keep a track of 1s 10

prefixZero[end] - prefixZero[start-1]  = prefixOne[end] - prefixOne[start-1]

prefixZero[end]  - prefixOne[end] =  + prefixZero[start-1] - prefixOne[start-1]
     3  cache->[3]

  11111111111

  101111111




        2   4
    0 0 0 0 1 0 1 0 1 0 1 0 1 0
0   1 2 3 4 4 5 5 6 6 7 7 8 8 9
1   0 0 0 0 1 0 2 0 3 0 4 0 5 0
            |
            3

prefixZero[end] - prefixZero[start-1]  = prefixOne[end] - prefixOne[start-1]

  //  number(1) = [number(0) ^ 2]

  prefixZero[end] - prefixZero[start-1]  = prefixOne[end] - prefixOne[start-1]
*/

int GoodString(string s)
{
  int n = s.size();

  vector<int> prefixZero(n, 0), prefixOne(n, 0);

  prefixZero[0] = (s[0] == '1' ? 0 : 1);
  prefixOne[0] = (s[0] == '0' ? 1 : 0);

  for (int i = 1; i < n; i++)
    prefixZero[i] = prefixZero[i - 1] + (s[i] == '0' ? 1 : 0);

  for (int i = 1; i < n; i++)
    prefixOne[i] = prefixOne[i - 1] + (s[i] == '1' ? 1 : 0);

  unordered_map<int, int> cache;

  int maxLen = 0;
  int prefixZero = 0;
  for (int i = 0; i < n; i++)
  {

    int endValue = prefixZero[i] - prefixOne[i];

    if (cache.find(endValue) != cache.end())
      maxLen = max(maxLen, i - cache[endValue]);

    cache.insert({endValue, i});
  }
  return maxLen;
}

int main()
{
  return 0;
}
