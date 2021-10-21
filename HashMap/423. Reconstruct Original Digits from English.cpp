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
  z e r o       - z
  o n e                                -n
  t w o         - w
  t h r e e           - h
  f o u r       - u        - f
  f i v e                  - f               -i
  s i x         - x              -s          -i
  s e v e n                      -s    -n
  e i g h t     - g   - h                    -i
  n i n e                              -n    -i
*/

class Solution
{
public:
  string originalDigits(string s)
  {
    vector<int> frequency(26, 0), nums(10, 0);
    for (char c : s)
      frequency[c - 'a']++;
    nums[0] = frequency['z' - 'a'];
    nums[2] = frequency['w' - 'a'];
    nums[4] = frequency['u' - 'a'];
    nums[1] = frequency['o' - 'a'] - nums[0] - nums[2] - nums[4];
    nums[3] = frequency['r' - 'a'] - nums[0] - nums[4];
    nums[6] = frequency['x' - 'a'];
    nums[7] = frequency['s' - 'a'] - nums[6];
    nums[8] = frequency['g' - 'a'];
    nums[5] = frequency['v' - 'a'] - nums[7];
    nums[9] = frequency['i' - 'a'] - nums[5] - nums[6] - nums[8];
    string ans;
    for (int i = 0; i < 10; i++)
      ans += string(nums[i], '0' + i);
    return ans;
  }
};
