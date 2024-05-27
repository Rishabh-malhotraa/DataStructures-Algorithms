
/* ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

// Minimum number of trees to plan so you get rid of polution

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A)
{
  int n = A.size();
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    int curr = A[i];
    int prev = i == 0 ? 0 : A[i - 1];
    int next = i == n - 1 ? 0 : A[i + 1];
    arr[i] = prev + curr + next;
    // cout << setw(5) << A[i] << setw(5) << arr[i] << endl;
  }

  int result = 0;

  for (int i = 0; i < n; i++)
  {
    int el = arr[i];
    if (el < 0)
    {
      result += abs(el);
      if (i + 1 < n)
      {
        arr[i + 1] += abs(el);
      }
      if (i + 2 < n)
      {
        arr[i + 2] += abs(el);
      }
    }
  }
  return result;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << solution(arr) << " " << endl;
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

