/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *arr[27];
  int index = -1;

  bool contains(char ch)
  {
    return arr[ch - 'a'] != NULL;
  }

  void put(char ch, Node *newNode)
  {
    arr[ch - 'a'] = newNode;
  }

  Node *getNext(char ch)
  {
    return arr[ch - 'a'];
  }

  void setIndex(int idx)
  {
    index = idx;
  }

  int getIndex()
  {
    return index;
  }
};

class WordFilter
{
  Node *trie;

public:
  void insert(Node *root, string &s, int idx)
  {
    for (auto &ch : s)
    {
      if (!root->contains(ch))
      {
        root->put(ch, new Node());
      }
      root = root->getNext(ch);
      root->setIndex(idx);
    }
  }

  WordFilter(vector<string> &words)
  {
    trie = new Node();

    int idx = 0;
    string s = "";

    for (auto &word : words)
    {
      s = "{" + word;
      insert(trie, s, idx);

      for (int i = word.size() - 1; i >= 0; i--)
      {
        s = word[i] + s;
        insert(trie, s, idx);
      }

      idx++;
    }
  }

  int f(string prefix, string suffix)
  {

    Node *temp = trie;

    string match = suffix + "{" + prefix;

    for (auto &ch : match)
    {
      if (!temp || !temp->contains(ch))
        return -1;
      temp = temp->getNext(ch);
    }

    return temp->getIndex();
  }
};