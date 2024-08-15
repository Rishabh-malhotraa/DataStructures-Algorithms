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
DAY    "5/1"  "5/5"  "5/9"

PTR     100    200

MSFT            50    100

AMZN    200           100

TOT     300    450    400    <- RETURN THIS

your input is ->
[
{{"5/1", 100}, {"5/5", 200}}  // PTR
{{"5/5", 50}, {"5/9", 100}}  // MSFT
{{"5/1", 200}, {"5/9", 100}}  // AMZN
*/

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

pair<int, int> getMonthDate(string s)
{
  int idx = s.find('/');
  return {stoi(s.substr(0, idx + 1)), stoi(s.substr(idx + 1))};
}

bool comparator(const pair<string, tuple<int, int>> &a, const pair<string, tuple<int, int>> &b)
{
  auto [month1, date1] = getMonthDate(a.first);
  auto [month2, date2] = getMonthDate(b.first);

  if (month1 < month2)
    return true;
  if (month1 == month2)
    return date1 < date2;
}

vector<pair<string, int>> getAmount(vector<vector<pair<string, int>>> &input)
{
  vector<pair<string, tuple<int, int>>> flattenInput;
  vector<pair<string, int>> result;

  for (int i = 0; i < input.size(); i++)
    for (int j = 0; j < input[i].size(); j++)
      flattenInput.push_back({input[i][j].first, {i, input[i][j].second}});

  // make sure this is sorted correctly!!!
  sort(flattenInput.begin(), flattenInput.end(), comparator);

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
