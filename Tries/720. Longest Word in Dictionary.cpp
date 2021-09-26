#include <bits/stdc++.h>
using namespace std;

// TRIE WITH DFS on TRIE

const int TRIE_SIZE = 26;
class TrieNode
{
public:
  bool isTerminal;
  vector<TrieNode *> children;

  TrieNode() : isTerminal(false), children(vector<TrieNode *>(TRIE_SIZE, NULL)) {}
};

class Trie
{
private:
  TrieNode *root;
  string getMax(string &s1, string &s2)
  {
    if (s1.size() == s2.size())
      return ((s1 < s2) ? s1 : s2);

    return (s1.size() > s2.size()) ? s1 : s2;
  }

  void search(TrieNode *curr, string s, string &result)
  {
    if (curr == NULL)
      return;

    result = getMax(s, result);

    for (int idx = 0; idx < TRIE_SIZE; idx++)
    {
      char ch = ('a' + idx);
      if (curr->children[idx] != NULL && curr->children[idx]->isTerminal == true)
        search(curr->children[idx], s + ch, result);
    }
  }

public:
  Trie() : root(new TrieNode()) {}

  void insert(string &s)
  {
    TrieNode *curr = root;

    for (char &ch : s)
    {
      int idx = ch - 'a';

      if (curr->children[idx] == NULL)
        curr->children[idx] = new TrieNode();
      curr = curr->children[idx];
    }
    curr->isTerminal = true;
  }

  string getMaxString()
  {
    TrieNode *curr = root;
    string result = "";
    search(curr, "", result);
    return result;
  }
};

class Solution
{
public:
  string longestWord(vector<string> &words)
  {
    Trie *t = new Trie();

    for (string &word : words)
      t->insert(word);

    return t->getMaxString();
  }
};