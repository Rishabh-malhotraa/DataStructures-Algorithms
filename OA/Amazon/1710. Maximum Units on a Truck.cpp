//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

long int getMaxUnit(int num, vector<int> boxes, int unitSize,
                    vector<int> unitsPerBox, long truckSize)
{
  vector<pair<int, int>> bx;

  int n = boxes.size();
  for (int i = 0; i < boxes.size(); i++)
    bx.push_back({unitsPerBox[i], boxes[i]});

  sort(bx.begin(), bx.end(), [](pair<int, int> &p1, pair<int, int> &p2)
       { return p1.first > p2.first; });

  long long result = 0;
  for (int i = 0; i < n; i++)
  {
    cout << truckSize << " " << result << endl;
    if (truckSize >= bx[i].second)
    {
      truckSize -= bx[i].second;
      result += bx[i].first * bx[i].second;
    }
    else
    {
      result += bx[i].first * truckSize;
      break;
    }
  }
  return result;
}
