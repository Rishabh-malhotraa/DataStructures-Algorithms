/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int l, r;

int getXor(int n)
{
  switch (n % 4)
  {
  case 0:
    return n;
  case 1:
    return 1;
  case 2:
    return n + 1;
  case 3:
    return 0;
  }
  return -1;
}

// get Xor from range of [L...r}
int x = getXor(l - 1) ^ getXor(r);