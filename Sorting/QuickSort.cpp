//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class QuickSort
{
public:
  void quickSort(vector<int> &arr, int l, int r)
  {
    if (l > r)
      return;
    int pivot = 0;

    for (int i = l; i <= r; i++)
      if (arr[i] >= arr[r])
        swap(arr[pivot++], arr[i]);

    pivot--;
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
  }
};
