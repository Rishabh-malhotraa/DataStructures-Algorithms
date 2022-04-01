/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {
    int prev = head->val;
    vector<int> result(2, INT_MAX);
    head = head->next;
    int idx = 1;
    vector<int> criticalPoints;
    while (head->next != NULL)
    {
      int curr = head->val;
      int next = head->next->val;

      if ((prev > curr && curr < next) || (prev < curr && curr > next))
        criticalPoints.push_back(idx);

      idx++;
      prev = curr;
      head = head->next;
    }

    if (criticalPoints.size() < 2)
      return {-1, -1};

    result[1] = criticalPoints.back() - criticalPoints.front();
    for (int i = 1; i < criticalPoints.size(); i++)
      result[0] = min(result[0], criticalPoints[i] - criticalPoints[i - 1]);

    return result;
  }
};