#include <bits/stdc++.h>
using namespace std;

/*
Balencing Left and Right Force (Left and Right Sweep)
? Input: dominoes = ".L.R...LR..L.."
? Output: "LL.RR.LLRRLL.."
*/

class Solution
{
public:
  string pushDominoes(string dominoes)
  {
    int n = dominoes.size();
    vector<int> left(n, 0), right(n, 0);
    int prev = 0;

    // Right Sweep
    for (int i = 0; i < n; i++)
    {
      if (dominoes[i] == 'R')
        right[i] = prev = n;
      else if (dominoes[i] == 'L')
        right[i] = prev = 0;
      else
        right[i] = max(--prev, 0);
    }

    prev = 0;

    // Left Sweep
    for (int i = n - 1; i >= 0; i--)
    {
      if (dominoes[i] == 'R')
        right[i] = prev = n;
      else if (dominoes[i] == 'L')
        right[i] = prev = 0;
      else
        right[i] = max(--prev, 0);
    }

    string result = "";
    // Balencing Forces
    for (int i = 0; i < n; i++)
    {
      int currForce = right[i] - left[i];

      char ch = currForce == 0 ? '.' : currForce > 0 ? 'R'
                                                     : 'L';
      result.push_back(ch);
    }
    return result;
  }
};