/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator
{
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator
{
private:
  bool hasNextIterator;
  int nextValue;

public:
  PeekingIterator(const vector<int> &nums) : Iterator(nums)
  {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    this->hasNextIterator = Iterator::hasNext();
    this->nextValue = Iterator::next();
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek()
  {
    return this->nextValue;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next()
  {
    int currValue = this->nextValue;

    this->hasNextIterator = Iterator::hasNext();

    if (this->hasNextIterator)
      this->nextValue = Iterator::next();

    return currValue;
  }

  bool hasNext() const
  {
    return this->hasNextIterator;
  }
};