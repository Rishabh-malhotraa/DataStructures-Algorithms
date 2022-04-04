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

/*

Input: head = [1,2,3,4,5], k = 2


1->2->3->4->5

Null->1->2->3->4->5
         |-----|
*/
class Solution
{
public:
  ListNode *swapNodes(ListNode *head, int k)
  {
    ListNode *e1 = head, *e2 = head;
    for (int i = 1; i < k; i++)
      e1 = e1->next;

    for (ListNode *offset = e1; offset->next != NULL; offset = offset->next)
      e2 = e2->next;

    swap(e1->val, e2->val);
    return head;
  }
};
