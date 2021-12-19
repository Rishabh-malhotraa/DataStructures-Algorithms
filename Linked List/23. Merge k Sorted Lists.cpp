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
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    vector<int> nums;

    for (ListNode *list : lists)
    {
      while (list != NULL)
      {
        nums.push_back(list->val);
        list = list->next;
      }
    }

    ListNode *preHead = new ListNode(), *curr = preHead;
    sort(nums.begin(), nums.end());
    for (int el : nums)
    {
      ListNode *node = new ListNode(el);
      curr->next = node;
      curr = curr->next;
    }
    return preHead->next;
  }
};