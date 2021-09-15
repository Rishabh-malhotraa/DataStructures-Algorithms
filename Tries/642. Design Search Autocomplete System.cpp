/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

// Very Length Problem, Not HARD!
// uses alot of cool concecpts

#include <bits/stdc++.h>
using namespace std;

int n = 28;
class TrieNode
{
public:
  vector<TrieNode *> children;
  int value;
  bool isTerminal;

  TrieNode() : value(0), isTerminal(false), children(vector<TrieNode *>(n, NULL)) {}
};

class Trie
{
private:
  TrieNode *root;

  int getIdx(char &ch)
  {
    if (ch == ' ')
      return 26;
    else if (ch == '#')
      return 27;
    else
      return ch - 'a';
  }

  char getChar(int &idx)
  {
    if (idx == 26)
      return ' ';
    else if (idx == 27)
      return '#';
    else
      return 'a' + idx;
  }

public:
  Trie() : root(new TrieNode()) {}

  void insert(string word, int value)
  {
    TrieNode *curr = root;
    for (char &ch : word)
    {
      int idx = getIdx(ch);

      if (curr->children[idx] == NULL)
        curr->children[idx] = new TrieNode();

      curr = curr->children[idx];
    }

    curr->isTerminal = true;
    curr->value += value;
  }

  vector<string> prefixSuggestion(string prefix)
  {
    TrieNode *curr = root;
    vector<pair<int, string>> result;
    for (char &ch : prefix)
    {
      int idx = getIdx(ch);
      if (curr->children[idx] == NULL)
        return {};
      curr = curr->children[idx];
    }

    queue<pair<TrieNode *, string>> q({{curr, prefix}});
    while (!q.empty())
    {
      TrieNode *curr = q.front().first;
      string s = q.front().second;
      q.pop();

      if (curr->isTerminal == true)
        result.push_back({curr->value, s});

      for (int i = 0; i < 28; i++)
      {
        TrieNode *neighbour = curr->children[i];
        char ch = getChar(i);
        if (neighbour != NULL)
          q.push({neighbour, s + ch});
      }
    }

    sort(result.begin(), result.end(), [](pair<int, string> &p1, pair<int, string> &p2)
         {
           if (p1.first == p2.first)
             return p1.second < p2.second;
           return p1.first > p2.first;
         });

    vector<string> recommendations;

    for (int i = 0; i < min((int)result.size(), 3); i++)
      recommendations.push_back(result[i].second);

    return recommendations;
  }
};

class AutocompleteSystem
{
private:
  string phrase;
  Trie *t;

public:
  AutocompleteSystem(vector<string> &sentences, vector<int> &times)
  {
    int n = sentences.size();
    t = new Trie();
    for (int i = 0; i < n; i++)
      t->insert(sentences[i], times[i]);
  }

  vector<string> input(char c)
  {
    if (c == '#')
    {
      t->insert(phrase, 1);
      phrase.clear();
      return {};
    }
    phrase.push_back(c);

    return t->prefixSuggestion(phrase);
  }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 

["i love you","island","iroman","i love leetcode"],[5,3,2,2]],

["i"],[" "],["a"],["#"],["i"],[" "],["a"],["#"],["i"],[" "],["a"],["#"]]
 

 OUTPUT
 [null,["i love you","island","i love leetcode"],
 ["i love you","i love leetcode"],
 [],
 [],
 ["i love you","island","i love leetcode"],
 ["i love you","i love leetcode","i a"],
 ["i a"],
 [],
 ["i love you","island","i love leetcode"],
 ["i love you","i love leetcode","i a"],
 ["i a"],
 []]
 
 
 EXPECTED
 [null,["i love you","island","i love leetcode"],
 ["i love you","i love leetcode"],
 [],
 [],
 ["i love you","island","i love leetcode"],
 ["i love you","i love leetcode","i a"],
 ["i a"],
 [],
 ["i love you","island","i a"],
 ["i love you","i a","i love leetcode"],
 ["i a"],
 []]

 */