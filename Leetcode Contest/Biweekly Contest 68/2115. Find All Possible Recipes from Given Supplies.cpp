/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  unordered_map<string, vector<string>> recipieGraph;
  unordered_map<string, int> visited;
  unordered_map<string, bool> dp;
  const int UNVISITED = -1, PROCESSING = 0, VISITED = 1;
  bool canAdd(string recipie, unordered_set<string> &supplies)
  {
    // cout << recipie << endl;
    if (visited[recipie] == PROCESSING)
      return false;

    if (dp.find(recipie) != dp.end())
      return dp[recipie];

    visited[recipie] = PROCESSING;
    vector<string> ingrediants = recipieGraph[recipie];

    for (string &ingrediant : ingrediants)
    {
      if (supplies.find(ingrediant) == supplies.end() && recipieGraph.find(ingrediant) == recipieGraph.end())
        return dp[recipie] = false;

      if (recipieGraph.find(ingrediant) != recipieGraph.end())
      {
        bool flag = canAdd(ingrediant, supplies);
        if (!flag)
          return dp[recipie] = false;
      }
    }
    visited[recipie] = VISITED;
    return dp[recipie] = true;
  }

public:
  vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
  {
    vector<string> availableRecipie;
    unordered_map<string, int> resetVisited;
    for (int i = 0; i < recipes.size(); i++)
    {
      this->recipieGraph[recipes[i]] = ingredients[i];
      resetVisited[recipes[i]] = -1;
    }

    unordered_set<string> suppliesSet(supplies.begin(), supplies.end());

    for (string recipie : recipes)
    {
      visited = resetVisited;
      // cout << recipie << endl;
      // cout << "---" << endl;

      bool possible = canAdd(recipie, suppliesSet);

      if (possible)
        availableRecipie.push_back(recipie);
    }

    return availableRecipie;
  }
};