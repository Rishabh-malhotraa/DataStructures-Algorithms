/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

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
  Trie(vector<string> words = {})
  {
    root = new TrieNode();

    for (string word : words)
      this->insert(word);
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

class Solution
{
public:
  int wordCount(vector<string> &startWords, vector<string> &targetWords)
  {
    for (string &word : startWords)
      sort(word.begin(), word.end());

    Trie *t = new Trie(startWords);
    int count = 0;

    for (string &word : targetWords)
    {
      sort(word.begin(), word.end());
      int n = word.size();
      for (int j = 0; j < n; j++)
      {
        string str = word.substr(0, j) + word.substr(j + 1);
        if (t->search(str))
        {
          count++;
          break;
        }
      }
    }
    return count;
  }
};
