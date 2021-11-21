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

ListNode *reverse(ListNode *node)
{
  ListNode *prev = NULL, *curr = node;

  while (curr != NULL)
  {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  return prev;
}

ListNode *getMiddleNode(ListNode *node)
{
  ListNode *fast = node, *slow = node;

  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

bool solve(ListNode *node)
{
  if (node == NULL || node->next == NULL)
    return true;

  ListNode *middle = getMiddleNode(node);
  middle = middle->next; // head for reversing the 2nd part

  ListNode *reverseHead = reverse(middle);

  while (reverseHead != NULL)
  {
    if (reverseHead->val != node->val)
      return false;
    reverseHead = reverseHead->next;
    node = node->next;
  }
  return true;
}
