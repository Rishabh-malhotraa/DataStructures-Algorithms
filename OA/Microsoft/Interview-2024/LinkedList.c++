#include <iostream>

// create a linked list

// add node in the middle

// delete node from the middle
// delete(index)

// O(1) O(1)

class LinkedList
{
public:
  int value;
  LinkedList *nextNode;
  LinkedList *prevNode;

  LinkedList(int value, LinkedList *nextNode)
  {
    this->value = value;
    this->nextNode = nextNode;
  }
};
//  k = 2
//                  **
// This 1 -- 2 -  3 -- 4  --5  -> NULL
//                |
//  k =- 6

class LinkedListService
{

  /*

  k = 3
          curr
    1         |
  0 - 1 -- 2 -> 3 -- 5  --6  -> NULL
  ^      **

  0 - 1 - 2 - 3 - 4
  

  hash -> pointer with index

  List

  index = 0
  k = 1


  */

  // add a node at the kth index
  void addNode(LinkedList *head, int value, int k)
  {
    LinkedList *curr = head;
    int index = 0;
    while (curr != NULL && index != k + 1)
    {

      if (index == k)
      {
        LinkedList newNode = new LinkedList(value, curr->nextNode);
        curr->nextNode = newNode;
        //
        // 2 --> [insert a new node]  -> 3
      }
      index++;
    }
    return;
  }

  /*
    k = 1 <>


    k =1
          *
    A -> B -> C  -> D -> NULL
          |
  */

  /*

   HEAD
            |
            2

    */
  main
  {
    LinkedList *list;
    //

    deleteNode(list, 0); // 123454 -> {}
    int headValue = list->value;
  }

  LinkedList *deleteNode(LinkedList *head, int k)
  {
    // HEAD ->

    LinkedList *curr = head;
    int index = 0;
    while (curr != NULL && index != k + 1)
    {

      if (index == 0)
      {
        head = curr->nextNode;
        delete (curr);
      }

      if (index == k && index != 0)
      {
        LinkedList *previous = curr->prevNode;
        LinkedList *next = curr->nextNode;
        previous->nextNode = next;
        next->prevNode = previous;

        delete (curr);
      }

      index++;
    }
    return head;
  }

  // int inovke(){
  //     LinkedList l = new LinkedList(1, null)

  // }
};

/*
   []    []    []

   [ Node ]  ->
      Value
    Pointer to the next node

*/

int main()
{
  // you can write to stdout for debugging purposes, e.g.
  std::cout << "This is a debug message" << std::endl;

  return 0;
}


class ListNode<T> {
  LinkedList<T> *previousNode;
  LinkedList<T> *nextNode;
  T value;
}

void deleteNode(ListNode<int> *&head, int k){
  ListNode<int> *dummyNode = new ListNode<int>(null, head, 0);
  ListNode<int> *curr = dummyNode;
  int i = 0;
  
  while(i++ <= k) curr=curr->next;

  ListNode<int> *prev = curr->previousNode;
  ListNode<int> *next = curr->nextNode;

  prev->next = next;

  delete(curr);

  head = dummyNode->next;
  return;
}

void addNode(ListNode<int> *&head, int k)
{
  ListNode<int> *dummyNode = new ListNode<int>(null, head, 0);
  ListNode<int> *curr = dummyNode;
  int i = 0;

  while (i++ <= k) curr = curr->next;

  ListNode<int> *node = new ListNode<int>(curr->prev, int value, curr);
  curr->previous->next = node;
  curr->previous = node; 

  head = dummyNode->next;
  return;
}

