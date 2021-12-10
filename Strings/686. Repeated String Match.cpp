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
https://leetcode.com/problems/repeated-string-match/
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc".



Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
Example 3:

Input: a = "a", b = "a"
Output: 1
Example 4:

Input: a = "abc", b = "wxyz"
Output: -1


Constraints:

1 <= a.length <= 10^4
1 <= b.length <= 10^4
a and b consist of lower-case English letters.
*/

/*
 x         y
abcc     abccab

a+a => b is a substring of a

append a some number of times such that b is a substring of a
           minimum


          x+x  => abccabcc
              sliding window of size = len(y) => abccac

abc   zy

we can have frequency map\

add all characters of x in set S


now take every charcter of y and check if its present in S


x      y
abc   bbbac
 X    X

the neighbours of a can be {c and b}



abcabc   bbbac


rrabin_karp(string) -> int



abc =>


if pass our x -> to that


abcabcabc

kmp algortihm?
 rabin karp

rather than append x

why dont we check y instead

  |-----------|
a b c a b c a b c


this should reutrn -1


return -1
S ={a,b,c}


1. Keep appending to x
have a sliding window of size = len of y to check if y exist in x


*/

/*
               -- {}     --
 Input: a = "abcd", b = "cdabcdab"
               X
we get all the candidate positions to start b

indez 2  ->  cd

*/

class Solution
{
private:
  int getRepetitions(int idx, string a, string b)
  {
    int m = b.size(), n = a.size(), repetitions = 1;
    string str = a.substr(idx);

    while (str.size() < m)
    {
      str += a;
      repetitions++;
    }

    return (str.substr(0, m) == b) ? repetitions : INT_MAX;
  }

public:
  int repeatedStringMatch(string a, string b)
  {
    char ch = b[0];
    vector<int> candidates;

    for (int i = 0; i < a.size(); i++)
      if (a[i] == ch)
        candidates.push_back(i);

    int repetitions = INT_MAX;

    if (candidates.size() == 0)
      return -1;

    // O(m*n)
    for (int i = 0; i < candidates.size(); i++)
    {
      int idx = candidates[i];
      int curr_repetitions = getRepetitions(idx, a, b);
      repetitions = min(repetitions, curr_repetitions);
    }

    return repetitions == INT_MAX ? -1 : repetitions;
  }
};
