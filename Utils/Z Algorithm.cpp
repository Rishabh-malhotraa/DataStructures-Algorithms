#include <bits/stdc++.h>
using namespace std;

// longest Proper Prefix
// all prefix for string s[0..n-1)

class ZAlgorithm
{
private:
  string text, pattern;

  // Trivial Algorithm O(n^2)
  void createZArrayNaive()
  {
    int n = text.size();
    for (int i = 0; i < n; i++)
    {
      while (z[i] + i < n && text[z[i]] == text[z[i] + i])
        z[i]++;
    }
  }

  // Efficient Algorithm O(n)
  void createZArray()
  {
    /**
     * 1. if string is in range of L-R
     *      then we can give a kickstart
     * 2. use the normal chracter checking logic
     * 3. we need to update the ranges too
     */
    //             - - - - -
    // a b a b a d a b a b a c
    // 0 0 3 0 1 0 5 0 3
    int n = text.size();
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
      //                                     |
      // if i is beyond know region [l----r]
      // then it is not possilbe to kickstart the given index
      if (i <= r)
        z[i] = min(r - i + 1, z[i - l]);
      while (z[i] + i < n && text[z[i]] == text[z[i] + i])
        z[i]++;

      // only benifit on updating is when the new range would be greater than the know range
      if (i + z[i] - 1 > r)
        l = i, r = i + z[i] - 1;
    }
  }

public:
  vector<int> z;
  ZAlgorithm(string &text, string &pattern)
  {
    this->text = text, this->pattern = pattern;
    z.assign(text.size(), 0);
  }
  /*
    create a z array for pattern#text
    pattern is matched at all those indices where z[i] == pattern.size()
  */
};

void solve()
{
  string text, pattern;
  cin >> text >> pattern;

  ZAlgorithm *sol = new ZAlgorithm(text, pattern);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}