//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getPermute(int n, int k)
  {
    if (n == 1)
      return 1;
    else
    {
      return k * getPermute(n - 1, k - 1);
    }
  }

  int countNumbersWithUniqueDigits(int n)
  {
    int result = 1;

    for (int i = 1; i <= n; i++)
    {
      result += 9 * getPermute(i, 9);
    }
    return result;
  }
};