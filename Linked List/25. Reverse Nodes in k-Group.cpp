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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (k == 1 || head == NULL)
      return head;

    ListNode *dummy = new ListNode(-1, head), *pre = dummy, *curr = head;
    int n = 0;
    while (curr != NULL)
    {
      n++;
      curr = curr->next;
    }
    curr = pre->next;

    // *    1 - 2 - 3 - 4
    // pre      cu

    for (int i = 0; i < n / k; i++)
    {
      for (int j = 0; j < k - 1; j++)
      {
        ListNode *temp = pre->next;
        pre->next = curr->next;
        curr->next = curr->next->next;
        pre->next->next = temp;
      }
      pre = curr;
      curr = curr->next;
    }
    return dummy->next;
  }
};