/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Similar to JUMP GAME II
// LC: 1326 Minimum number of taps to open to water a garden

using namespace std;
int main()
{
  int n;

  cin >> n;
  vector<int> location(n, 0), range(n + 1, 1);

  for (int i = 0; i < n; i++)
    cin >> location[i];

  for (int i = 1; i <= n; i++)
  {
    int minVal = max(1, i - location[i - 1]);
    int maxVal = min(n, i + location[i - 1]);
    range[minVal] = max(maxVal - minVal + 1, range[minVal]);
  }

  int bombs = 0, currEnd = 1, currFarthest = 1;

  for (int i = 1; i <= n; i++)
  {
    currFarthest = max(currFarthest, i + range[i]);
    if (i == currEnd)
    {
      bombs++;
      currEnd = currFarthest;
    }
  }
  cout << bombs << endl;

  return 0;
}
