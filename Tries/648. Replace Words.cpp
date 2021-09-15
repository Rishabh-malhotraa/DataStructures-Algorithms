/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 26;

class TrieNode
{
public:
  bool isTerminal;
  vector<TrieNode *> children;
  TrieNode()
  {
    children.assign(N, NULL);
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
      int idx = ch - 'a';

      if (node->children[idx] == NULL)
        node->children[idx] = new TrieNode();

      node = node->children[idx];
    }
    node->isTerminal = true;
  }

  string getShortestPrefix(string &word)
  {
    TrieNode *node = root;
    int n = 0;
    for (char ch : word)
    {
      int idx = ch - 'a';

      if (node->children[idx] == NULL)
        return word;

      node = node->children[idx];
      n++;

      if (node->isTerminal)
        return word.substr(0, n);
    }
    return word;
  }
};

class Solution
{
public:
  string replaceWords(vector<string> &dictionary, string sentence)
  {
    Trie *t = new Trie();

    // building prefix tree
    for (string &word : dictionary)
      t->insert(word);

    string result, token;
    sentence.push_back(' ');

    stringstream ss(sentence);

    while (getline(ss, token, ' '))
      result += t->getShortestPrefix(token);

    return result;
  }
};