// CODECHEF July Cook-off IV

#include <bits/stdc++.h>
using namespace std;

int ModEquality(vector<int> &arr)
{
  int n = arr.size();
  int num = *min_element(arr.begin(), arr.end());
  int count = 0;

  for (int el : arr)
  {
    if (el == num)
      continue;
    else
    {
      int modular = el - num;
      if (el % modular != num)
        return n;
      else
        count++;
    }
  }
  return count;
}

int solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << ModEquality(arr) << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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