#include <bits/stdc++.h>
using namespace std;

// Combinational Sum

class Solution
{
private:
  int result;

public:
  int compatibility(vector<int> &mentor, vector<int> &student)
  {
    int count = 0;
    for (int i = 0; i < mentor.size(); i++)
    {
      if (mentor[i] == student[i])
        count++;
    }
    return count;
  }

  void dfs(vector<vector<int>> &students, vector<vector<int>> &mentors, vector<bool> &visited, int index, int processed, int currCount)
  {

    if (processed == mentors.size())
    {
      // cout << index << endl;
      result = max(currCount, result);
      // cout << endl;
      return;
    }

    for (int i = 0; i < mentors.size(); i++)
    {
      if (visited[i] == true)
        continue;

      int increaseCount = compatibility(students[index], mentors[i]);

      currCount += increaseCount;
      visited[i] = true;
      // cout << index << " " << i << " " << processed << " " << currCount << endl;

      // move onto the next element.
      dfs(students, mentors, visited, index + 1, processed + 1, currCount);

      currCount -= increaseCount;
      visited[i] = false;
    }

    return;
  }

  int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
  {
    // this could be done by making substed
    int n = students.size();
    vector<bool> visited(n, false);
    dfs(students, mentors, visited, 0, 0, 0);
    return result;
  }
};