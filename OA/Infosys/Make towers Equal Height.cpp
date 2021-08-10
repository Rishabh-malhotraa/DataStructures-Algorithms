/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int add, del, move;
  cin >> add >> del >> move;
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
    cin >> heights[i];

  int operation = min({add, del, move});
  int sum_of_towers = accumulate(heights.begin(), heights.end(), 0);
  int max_height = *max_element(heights.begin(), heights.end());
  int min_height = *min_element(heights.begin(), heights.end());

  int cost = INT_MAX;

  // if (operation == move){}
  int el = sum_of_towers / n;
  int rem = sum_of_towers % n;
  int changes = 0;
  for (int &h : heights)
    changes += abs(el - h);

  int rem_cost = min((rem)*del, (el - rem) * add);
  cost = rem_cost + (changes / 2) * operation;

  // else if (operation == add){}
  int changes = 0;
  for (int &h : heights)
    changes += (max_height - h);

  cost = min(cost, changes * operation);

  // else if (operation == del){  }
  int changes = 0;
  for (int &h : heights)
    changes += (h - min_height);

  cost = min(cost, changes * operation);

  cout << cost << endl;
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
3
100
100
1
3
1 3 8
1
100
100
3
1 3 8
100
1
100
3
1 3 8
*/