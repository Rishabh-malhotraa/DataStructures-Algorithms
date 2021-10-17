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
Wee need to plan a meeting

we are given schedule of 2 people

duration of the meeting should be dur

return [] if not possibble
else return start and end time


we can assume that both sloA and slotB are in sorted order by time




 duration                       60 -> 60 + duration
A         10-------------50     60---------------120   140 ---> 210
B : 0  -------- 15        |     60 ------ 70


slot A

find all  overlaps

and then get the first overlap which has duration > dur


10 -- 15
60 - 70


slot A first time 10
slot B firts time = 0


0 - 15
 10 - 50
  60 - 70
  60 -120


having one data struce to hold sometime for A

and the compare it with B


          |
10 - 50   60-120  - 140 -210



  /// https://www.linkedin.com/in/shankyrox/
0-15    60-70

         |

// time complexity O(M+N)

  // we want to increase the duration
  // the duration is capped by the value with lower end time
  // so move the idx of the array with would increase the endtime
  // if min(end, )
  // < dur

           < 5 >

  max(startA[i], starB[j]) - min(endA[i], endB[j]) => 5

*/

vector<int> meetingPlanner(const vector<vector<int>> &slotsA, const vector<vector<int>> &slotsB, int dur)
{
  int idxA = 0, idxB = 0;
  int n = slotsA.size(), m = slotsB.size();
  while (idxA < n && idxB < m)
  {

    int startTime = max(slotsA[idxA][0], slotsB[idxB][0]);
    int endTime = min(slotsA[idxA][1], slotsB[idxB][1]);

    int duration = endTime - startTime;
    cout << duration << endl;

    if (duration >= dur)
      return {startTime, startTime + dur};

    else
    {
      if (slotsA[idxA][1] > slotsB[idxB][1])
        idxB++;
      else
        idxA++;
    }
  }

  return {};
  // your code goes here
}

/* https:// github.com/Rishabh-malhotraa/caucus */

int main()
{
  return 0;
}