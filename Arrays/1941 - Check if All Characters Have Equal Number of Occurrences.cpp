#include <bits/stdc++.h>
using namespace std;

// hashmap frequency array

class Solution
{
public:
  bool areOccurrencesEqual(string s)
  {
    unordered_map<char, int> freq;

    for (char ch : s)
      freq[ch]++;

    int curr = freq[s[0]];

    for (auto el : freq)
    {
      if (el.second != curr)
        return false;
    }

    return true;
  }
};