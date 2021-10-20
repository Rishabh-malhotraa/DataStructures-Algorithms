/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int getDifferentNumber(const vector<int> &brr)
{
  vector<int> arr = brr;

  int n = arr.size(), i = 0;
  while (i < n)
  {
    if (arr[i] >= n || arr[i] == i)
      i++;
    else
    {
      int position = arr[i];
      swap(arr[i], arr[position]);
    }
  }

  for (int j = 0; j < n; j++)
    if (arr[j] != j)
      return j;

  return n;
}

int main()
{
  return 0;
}