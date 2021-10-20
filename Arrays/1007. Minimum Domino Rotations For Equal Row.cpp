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

we could make every value in Domino A either A[0] || B[0]
or
we could make every value in Domino B either A[0] || B[0]

1 X X 4 X 8 X
4 X X X X 7 X
*/

int getRotations(int value, vector<int> &a, vector<int> &b)
{
  int rotations = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != value)
    {
      if (b[i] == value)
        rotations++;
      else
        return INT_MAX;
    }
  }
  return rotations;
}

class Solution
{
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
  {
    int rotations = INT_MAX;

    rotations = min({rotations, getRotations(tops[0], tops, bottoms), getRotations(tops[0], bottoms, tops)});
    rotations = min({rotations, getRotations(bottoms[0], tops, bottoms), getRotations(bottoms[0], bottoms, tops)});

    return rotations == INT_MAX ? -1 : rotations;
  }
};

// inefficeint solution
class Solution
{
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
  {
    set<int> s(tops.begin(), tops.end());
    int rotations = INT_MAX;

    for (int el : s)
      rotations = min(rotations, getRotations(el, tops, bottoms));

    s = set<int>(bottoms.begin(), bottoms.end());

    for (int el : s)
      rotations = min(rotations, getRotations(el, bottoms, tops));

    return rotations == INT_MAX ? -1 : rotations;
  }
};

/*
  set<int> s1(tops.begin(), tops.end()), s2(bottoms.begin(), bottoms.end());
  int rotations = INT_MAX;
  vector<int> unionSet;
  set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(unionSet));

  if (unionSet.size() == 0 || unionSet.size() > 2)
    return -1;

  for (int el : unionSet)
    rotations = min({rotations, getRotations(el, tops, bottoms), getRotations(el, bottoms, tops)});

  return rotations == INT_MAX ? -1 : rotations;
*/