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
  bool isTerminal;

  TrieNode()
  {
    children.assign(26, NULL);
    isTerminal = false;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  /** Initialize your data structure here. */
  Trie()
  {
    root = new TrieNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    TrieNode *curr = root;
    for (int ch : word)
    {
      int idx = ch - 'a';
      if (curr->children[idx] == NULL)
        curr->children[idx] = new TrieNode();

      curr = curr->children[idx];
    }
    curr->isTerminal = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    TrieNode *curr = root;
    for (char ch : word)
    {
      int idx = ch - 'a';
      if (curr->children[idx] == NULL)
        return false;
      curr = curr->children[idx];
    }

    return curr->isTerminal;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    TrieNode *curr = root;
    for (char ch : prefix)
    {
      int idx = ch - 'a';
      if (curr->children[idx] == NULL)
        return false;
      curr = curr->children[idx];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */