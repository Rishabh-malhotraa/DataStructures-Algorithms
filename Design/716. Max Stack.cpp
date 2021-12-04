/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class MaxStack
{
private:
  list<int> stack;
  map<int, vector<list<int>::iterator>> maxStack;

  void deleteKey(int value)
  {
    maxStack[value].pop_back();
    if (maxStack[value].empty())
      maxStack.erase(value);
  }

public:
  MaxStack()
  {
  }

  void push(int x)
  {
    stack.push_front(x);
    maxStack[x].push_back(stack.begin());
  }

  int pop()
  {
    int value = stack.front();

    stack.pop_front();
    deleteKey(value);
    return value;
  }

  int top()
  {
    return stack.front();
  }

  int peekMax()
  {
    return maxStack.rbegin()->first;
  }

  int popMax()
  {
    int value = peekMax();
    list<int>::iterator it = maxStack[value].back();
    stack.erase(it);
    deleteKey(value);
  }
};

/*

 WRONG SOLUTION || SPENT ALOT OF TIME ON THIS HAHA

  why is this wromg?
  well mapping of [idx] -> iterator is not valid

  as deleting an idx in between would effect all the element after it

        (3) (4)
  1 2 3 4   5
      X
  deleteing 3 -> in map idx of 4 should now become 3 and 5 -> 4

  so this maping is not stable and does not work!

*/

class MaxStack
{
private:
  unordered_map<int, list<int>::iterator> keys;
  set<pair<int, int>> maxStack;
  list<int> stack;

  void printStacks()
  {
    cout << "STACK Value      ";
    for (int el : stack)
      cout << el << " ";

    cout << endl;
    cout << "MAX STACK Value  ";
    for (auto [value_, n_] : maxStack)
      cout << value_ << " ";
    cout << endl;
  }

public:
  MaxStack()
  {
  }

  void push(int x)
  {
    int n = stack.size();
    stack.push_back(x);
    maxStack.insert({x, n});
    cout << "push " << x << endl;

    list<int>::iterator it = stack.end();
    keys[n] = --it;

    printStacks();
  }

  int pop()
  {
    int value = stack.back(), n = stack.size() - 1;
    auto it = maxStack.find({value, n});
    maxStack.erase(it);
    stack.pop_back();
    keys.erase(n);

    cout << "pop " << value << endl;
    printStacks();

    return value;
  }

  int top()
  {
    cout << "top " << stack.back() << endl;
    printStacks();
    return stack.back();
  }

  int peekMax()
  {
    cout << "peekMax " << maxStack.rbegin()->first << endl;
    printStacks();
    return maxStack.rbegin()->first;
  }

  int popMax()
  {

    pair<int, int> map_el = *maxStack.rbegin();
    int value = map_el.first;
    int index = map_el.second;

    list<int>::iterator it = keys[index];

    keys.erase(index);
    stack.erase(it);

    cout << "LAST ELEMENT" << maxStack.end()->first << endl;
    maxStack.erase(--maxStack.end());

    cout << "popMax " << value << endl;
    printStacks();

    return value;
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  MaxStack obj;

  /*

  ["MaxStack","push","peekMax","push","peekMax","push","pop","pop","push","peekMax","push","popMax","top","push","push","peekMax","popMax","popMax"]
  [[],          [92],[],         [54],      [],   [22],   [],[],    [-57],    [],     [-24],   [],[],      [26],[-71],[],[],[]]

  */

  obj.push(92);
  obj.peekMax();
  obj.push(54);
  obj.peekMax();
  obj.push(22);
  obj.pop();
  obj.pop();
  obj.push(-57);
  obj.peekMax();
  obj.push(-24);
  obj.popMax();
  obj.top();
  obj.push(26);
  obj.push(-71);
  obj.peekMax();
  obj.popMax();
  obj.popMax();
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}