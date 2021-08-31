/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */

// find a possible candidate
// validate the possible candidate

// Time Complexity O(N) -> Two Pass and O(1) Space Complexity
bool knows(int a, int b)
{
  return false;
}

class Solution
{
public:
  int findCelebrity(int n)
  {
    int celebrity = 0;
    for (int i = 1; i < n; i++)
      if (knows(celebrity, i) == true)
        celebrity = i;

    for (int i = 0; i < n; i++)
      if (i != celebrity && (knows(celebrity, i) || !knows(i, celebrity)))
        return -1;

    return celebrity;
  }
};