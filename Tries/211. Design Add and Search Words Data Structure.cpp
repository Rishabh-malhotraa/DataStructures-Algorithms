/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

int N = 26;

class TrieNode
{
public:
  vector<TrieNode *> children;
  bool isTerminal;

  TrieNode() : children(vector<TrieNode *>(N, NULL)), isTerminal(false) {}
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  TrieNode *getRoot()
  {
    return root;
  }

  void insert(string key)
  {
    TrieNode *curr = root;
    for (char &ch : key)
    {
      int idx = ch - 'a';
      if (curr->children[idx] == NULL)
        curr->children[idx] = new TrieNode();
      curr = curr->children[idx];
    }

    curr->isTerminal = true;
  }

  bool search(string key, TrieNode *node, int idx)
  {
    int n = key.size();
    for (int i = idx; i < n; i++)
    {
      if (key[i] != '.')
      {
        int j = key[i] - 'a';
        if (node->children[j] == NULL)
          return false;
        node = node->children[j];
      }
      else
      {
        for (TrieNode *neighbour : node->children)
        {
          if (neighbour)
          {
            bool match = search(key, neighbour, i + 1);
            if (match)
              return true;
          }
        }
        return false;
      }
    }

    return node->isTerminal;
  }
};

class WordDictionary
{
private:
  Trie *t;

public:
  /** Initialize your data structure here. */
  WordDictionary()
  {
    t = new Trie();
  }

  void addWord(string word)
  {
    t->insert(word);
  }

  bool search(string word)
  {
    return t->search(word, t->getRoot(), 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */