
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
public:
  vector<TrieNode *> children;
  bool isTerminal;
  TrieNode()
  {
    children.assign(ALPHABET_SIZE, NULL);
    isTerminal = false;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }
  void insert(string key)
  {
    TrieNode *node = root;
    for (char ch : key)
    {
      char index = ch - 'a';
      if (node->children[index] == NULL)
        node->children[index] = new TrieNode();

      node = node->children[index];
    }
    node->isTerminal = true;
  }

  bool search(string key, bool searchPrefix = false)
  {
    TrieNode *node = root;

    for (char ch : key)
    {
      int index = ch - 'a';
      if (node->children[index] == NULL)
        return false;

      node = node->children[index];
    }

    return searchPrefix ? true : node->isTerminal;
  }
};
