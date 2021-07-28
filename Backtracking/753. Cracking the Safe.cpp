#include <bits/stdc++.h>
using namespace std;

// Backtracking | Math | Euler path | Graph | HashMap | De Brujin Graph | Greedy

// number of substrings can be(k ^ n)

// Brute force way of trying out every combination

/*
  Intuition:
  Realize that the shortest possible path involves adding every possible
  pass code in a sequence where the first (n_passcode - 1) elements overlap
  with the last (n_passcode - 1) elements of the solution.
*/

class Solution
{
private:
  bool isSmallestCode(string &s, unordered_set<string> &cache, int n, int k)
  {
    if (cache.size() == (int)pow(k, n))
      return true;
    else
    {
      for (int i = 0; i < k; i++)
      {
        char ch = '0' + i;
        s.push_back(ch);

        string passkey = s.substr(s.size() - n);

        if (cache.find(passkey) == cache.end())
        {
          cache.insert(passkey);
          if (isSmallestCode(s, cache, n, k))
            return true;
          cache.erase(passkey);
        }
        s.pop_back();
      }
    }
    return false;
  }

public:
  string crackSafe(int n, int k)
  {
    string s(n, '0');

    unordered_set<string> cache = {s};
    isSmallestCode(s, cache, n, k);
    return s;
  }
};
