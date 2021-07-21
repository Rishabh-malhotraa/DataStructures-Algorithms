#include <bits/stdc++.h>
using namespace std;

// Standard DFS

// Definition for Employee.
class Employee
{
public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution
{
private:
  int dfs(Employee *user, unordered_map<int, Employee *> &visited, int &sum)
  {
    sum += user->importance;
    for (int el : user->subordinates)
      dfs(visited[el], visited, sum);
    return sum;
  }

public:
  int getImportance(vector<Employee *> employees, int id)
  {
    unordered_map<int, Employee *> keys;
    for (auto employee : employees)
      keys[employee->id] = employee;
    int sum = 0;
    return dfs(keys[id], keys, sum);
  }
};
