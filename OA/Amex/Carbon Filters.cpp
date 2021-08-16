//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

/*
I missed some correctness cases in this  [4/6]

And almost all time complexity cases URGHHHHHH .l. -_- [1/4]

*/

/*
Example test:   'a?bb'
OK

Example test:   '??abb'
OK

Example test:   'a?b?aa'
OK

Example test:   'aa??aa'
OK

Your test case: ['???']
Returned value: 'aab'

*/

string solution(string &s)
{
  int n = s.size();
  string str = "ab";
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
    {
      for (int j = 0; j < 2; j++)
      {
        s[i] = str[j];

        char left = (i == 0) ? 'z' : s[i - 1];
        char leftleft = (i - 2 < 0) ? 'z' : s[i - 2];

        char right = (i == n - 1) ? 'z' : s[i + 1];
        char rightright = (i + 2 >= n) ? 'z' : s[i + 2];

        if (!(left == s[i] && s[i] == right) && !(left == leftleft && left == s[i]) && !(right == s[i] && right == rightright))
          break;
      }
    }
  }
  return s;
}
