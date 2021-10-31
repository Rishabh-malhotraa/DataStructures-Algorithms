/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

bool solution(vector<int> &A, vector<int> &B, int S)
{
  set<pair<int, int>> slots;
  int n = A.size();
  if (n > S)
    return false;

  set<int> s;
  for (int i = 0; i < n; i++)
  {
    s.insert(A[i]);
    s.insert(B[i]);
  }

  if (s.size() < n)
    return false;

  for (int i = 0; i < n; i++)
  {
    pair<int, int> current = {B[i], A[i]};
    pair<int, int> currRev = {A[i], B[i]};
    if (slots.find(current) == slots.end())
      slots.insert(current);
    else if (slots.find(currRev) == slots.end())
      slots.insert(currRev);
    else
      return false;
  }
  return true;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n), brr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
    cin >> brr[i];

  cout << (solution(arr, brr, k) ? "TRUE" : "FALSE") << endl;

  return;
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

/*

4
3 3
1 1 3
2 2 1
4 3
3 2 3 1
1 3 1 2
4 8
2 5 6 5
5 4 2 2
7 10
  1 2 1 6 8 7 8
  2 3 4 7 7 8 7


*/