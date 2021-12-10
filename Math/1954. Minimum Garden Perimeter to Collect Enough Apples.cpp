/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // crazy stupid mathematical observation
  // i and 2i appear 4 times and every value in between i and 2i appears 8 times

  long long minimumPerimeter(long long neededApples)
  {
    long long i = 1;
    for (i = 1; neededApples > 0; i++)
    {
      long long apples = (2 * i + i) * 4;
      apples += 8 * ((2 * i * (2 * i - 1) / 2) - ((i) * (i + 1) / 2));
      neededApples -= apples;
    }
    return 8 * (i - 1);
  }
};