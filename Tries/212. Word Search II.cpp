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
public:
  TrieNode *root;
  Trie(vector<string> words = {})
  {
    root = new TrieNode();

    for (string &word : words)
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
  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int m, n;
  bool isValid(int i, int j)
  {
    return (i >= 0 && i < m && j >= 0 && j < n);
  }

  void dfs(int i, int j, string &word, TrieNode *root, set<string> &result, vector<vector<char>> &grid, vector<vector<bool>> &visited)
  {
    if (root->isTerminal)
      result.insert(word + grid[i][j]);

    word.push_back(grid[i][j]);
    visited[i][j] = true;
    for (auto [di, dj] : dir)
    {
      int ni = i + di, nj = j + dj;
      if (isValid(ni, nj) == false || visited[ni][nj] == true)
        continue;

      int key = grid[ni][nj] - 'a';
      if (root->children[key] != NULL)
        dfs(ni, nj, word, root->children[key], result, grid, visited);
    }
    word.pop_back();
    visited[i][j] = false;
  }

public:
  vector<string> findWords(vector<vector<char>> &grid, vector<string> &words)
  {
    m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    Trie *t = new Trie(words);
    set<string> result;
    string s;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        TrieNode *root = t->root;
        int key = grid[i][j] - 'a';
        if (root->children[key])
          dfs(i, j, s, root->children[key], result, grid, visited);
      }
    }
    return vector<string>(result.begin(), result.end());
  }
};