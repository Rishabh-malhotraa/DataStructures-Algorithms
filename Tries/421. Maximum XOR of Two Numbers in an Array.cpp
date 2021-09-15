/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  vector<TrieNode *> children;
  TrieNode() : children(vector<TrieNode *>(2, NULL)) {}
};

class Conversion
{
protected:
  string getBinaryString(unsigned int nums)
  {
    string s;
    for (int i = 31; i >= 0; i--)
    {
      unsigned int mask = 1 << i;
      s += ((mask & nums) ? '1' : '0');
    }
    return s;
  }
  int getNumber(string s)
  {
    int n = s.size() - 1, result = 0;
    for (int i = n - 1; i >= 0; i--)
      if (s[i] == '1')
        result += 1 << (n - 1 - i);
    return result;
  }
};

class Trie : Conversion
{
private:
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  void insert(int num)
  {
    string key = this->getBinaryString(num);
    TrieNode *curr = root;
    for (char ch : key)
    {
      int idx = ch - '0';
      if (curr->children[idx] == NULL)
        curr->children[idx] = new TrieNode();
      curr = curr->children[idx];
    }
  }

  TrieNode *getRoot()
  {
    return root;
  }

  int getMaximum(TrieNode *r1, TrieNode *r2, string s)
  {
    if (r1 == NULL || r2 == NULL)
      return this->getNumber(s);

    TrieNode *c1 = r1->children[0], *c2 = r1->children[1];
    TrieNode *c3 = r2->children[0], *c4 = r2->children[1];

    if ((c1 && c4) || (c2 && c3))
      return max(getMaximum(c1, c4, s + '1'), getMaximum(c2, c3, s + '1'));
    else
      return max(getMaximum(c1, c3, s + '0'), getMaximum(c2, c4, s + '0'));
  }
};

class Solution
{
public:
  int findMaximumXOR(vector<int> &nums)
  {
    Trie *t = new Trie();

    for (int num : nums)
      t->insert(num);

    return t->getMaximum(t->getRoot(), t->getRoot(), "");
  }
};