/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
Question is Very Similar to LFU Cache
Once a key is increased, we move the key from current row to last row if last_row.val = current_row.val + 1.
Otherwise, we insert a new row before current row with vallue current_row.val + 1, and move the key to to the new row.
The logic of decrement operation is similar. Obviously, by doing this, the rows will keep its descending order.


head --- ValueNode1 ---- ValueNode2 ---- ... ---- ValueNodeN --- tail
              |               |                       |
            first           first                   first
              |               |                       |
           KeyNodeA        KeyNodeE                KeyNodeG
              |               |                       |
           KeyNodeB        KeyNodeF                KeyNodeH
              |                                       |
           KeyNodeC                                KeyNodeI
              |
           KeyNodeD




*/

class Row
{
public:
  list<string> stream;
  int count;
  Row(const string &s, int c) : stream({s}), count(c){};
};

class AllOne
{
private:
  list<Row> matrix;
  unordered_map<string, pair<list<Row>::iterator, list<string>::iterator>> keymap;

public:
  unordered_map<string, list<int>::iterator> minPos, maxPos;
  AllOne()
  {
  }

  void inc(string key)
  {
  }

  void dec(string key)
  {
  }

  string getMaxKey()
  {
    return matrix.empty() ? "" : matrix.front().stream.front();
  }

  string getMinKey()
  {
    return matrix.empty() ? "" : matrix.back().stream.front();
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */