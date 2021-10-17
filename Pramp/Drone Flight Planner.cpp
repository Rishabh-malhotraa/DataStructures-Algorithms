#include <iostream>
#include <vector>

using namespace std;

/*
we are given a drone


UP --   we need  -- 1kwh

Down -- we gain  --  1kwh


[ [0,   2, 10],s
  [3,   5,  0],10
  [9,  20,  6],4
  [10, 12, 15],   /// 4  + {x} = 15 - 6
  [10, 10,  8] ]

10 -> 0 (-10)

0 -> 6   {+6}

6-> 15  {+ 9}

15 -> 8 {-7}


-10 + 6 + 9 - 7

15 - 10 - 7 = 2


0--->{0} --> { 9 + 6}
8    15      6 0 10

      ()
0     0       9     15    (15-10)
8 ---.15  --  6  --  0   - 10

                            |


cost  = 9 + 6 = 15 - 10 =  5
*/

int calcDroneMinEnergy(const vector<vector<int>> &route)
{
  int n = route.size();
  int cost = 0;

  int next = route[n - 1][2];

  for (int i = n - 1; i >= 0; i--)
  {
    int curr = route[i][2];
    cost += (next - curr);
    if (cost < 0)
      cost = 0;

    next = curr;
  }

  return cost;
}

int main()
{
  return 0;
}