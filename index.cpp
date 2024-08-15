/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int getLastHolding(vector<pair<string, int>> &dateAmount, string date)
{
  // this can be done in log(N) time using binary search
  for (int i = 0; i < dateAmount.size(); i++)
  {
    auto &[currDate, amount] = dateAmount[i];
    if (date == currDate)
      return i == 0 ? 0 : dateAmount[i - 1].second;
  }
  return 0;
}

vector<pair<string, int>> getAmount(vector<vector<pair<string, int>>> &input)
{
  vector<pair<string, tuple<int, int>>> flattenInput;
  vector<pair<string, int>> result;

  for (int i = 0; i < input.size(); i++)
    for (int j = 0; j < input[i].size(); j++)
      flattenInput.push_back({input[i][j].first, {i, input[i][j].second}});

  int total = 0;
  string date;
  for (int i = 0; i < flattenInput.size(); i++)
  {
    date = flattenInput[i].first;
    if (i != 0 && date != flattenInput[i - 1].first)
      result.push_back({flattenInput[i - 1].first, total});

    auto &[company, stocks] = flattenInput[i].second;
    total += stocks - getLastHolding(input[company], date);
  }
  result.push_back({date, total});

  return result;
}
