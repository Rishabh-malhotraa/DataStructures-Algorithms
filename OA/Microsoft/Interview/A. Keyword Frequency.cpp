#include <bits/stdc++.h>
using namespace std;

/*
Return the frequency of keywords that match in text.
Microsoft hires software engineers every year from colleges, a typical software engineer to code on computer.
Microsoft Engineer works on large scale systems. Microsoft is an equal opportunity provider


keywords = {'Microsoft' , 'Microsoft Engineer', 'engineer', 'Software Engineer'}

frequency of keywords

Microsoft            -> 2  (Not 3 since Microsoft Engineer does not match with Microsoft)

Microsoft Engineer   -> 1

Engineer             -> 1

Software Engineer    -> 0

*/

/*
if the current words matches with any of the trienode

then see if it further matches with any of it chidlren
  -> if it matches -> go ahead and check this condition again
  -> increase the counter by 1 of the word that matches


Microsoft Enginerer
Microsoft

                   |
Microsoft Engineer works on large scale systems. Microsoft is an equal opportunity provider

currWord = Microsft

improve the incrementation process

*/

class TrieNode
{
public:
  unordered_map<string, TrieNode *> children;
  bool isTerminal;
  TrieNode(bool isTerminal = false)
  {
    this->isTerminal = isTerminal;
  }
};

vector<string> tokenizeWords(string &s)
{
  vector<string> words;
  stringstream ss(s);
  string token;
  char delimeter = ' ';
  while (getline(ss, token, delimeter))
    words.push_back(token);
  return words;
}

class Trie
{
private:
  TrieNode *root;

public:
  Trie(vector<string> &keywords)
  {
    root = new TrieNode();
    for (string &word : keywords)
      this->insert(tokenizeWords(word));
  }

  void insert(vector<string> &words)
  {
    TrieNode *node = root;
    for (string word : words)
    {
      if (node->children.find(word) == node->children.end())
        node->children[word] = new TrieNode();

      node = node->children[word];
    }
    node->isTerminal = true;
  }
  TreiNode *getRootPointer()
  {
    return root;
  }
};

unordered_map<string, int> find_frequeuncy(vector<string> &file_names, vector<string> &keywords)
{
  vector<string> words;
  for (string filename : file_names)
  {
    vector<string> words_ = tokenizeWords(filename);
    words.insert(words.end(), words_.begin(), words_.end());
  }

  Trie *t = new Trie(keywords);

  int i = 0;
  unordered_map<string, int> freq;

  int n = words.size();

  while (i < n)
  {
    TrieNode *node = t->getRootPointer();

    // if current word in text does not match skip
    if (node->children.find(words[i]) == node->children.end())
      i++, continue;

    string currWord = "";
    while (node->children.find(words[i]) != node->children.end())
    {
      currWord += words[i];
      node = node->children[words[i]];
      i++;
    }
    freq[currWord] += 1;
  }
  return freq;
}

/*

  X -> Y

Microsoft -> Microsft Engieer
Software -> Software Engineer



Microsoft hires software engineers every year from colleges, a typical software engineer to code on computer.


                                                 Microsoft
Microsoft Engineer works on large scale systems. Microsoft is an equal opportunity provider



   M
   I
   C
   R
   O
   S
   O
   F
   T  -> terminal

   E
   N
   G
   I
   N
   E
   E
   R  ->terminal


   so the condition we have to take care of is prefixes


Microsoft hires software engineers every year from colleges, a typical software engineer to code on computer.


                                                 Microsoft
Microsoft Engineer works on large scale systems. Microsoft is an equal opportunity provider

map<string, int> find_frequeuncy(vector<string> fine_name, vector<string> keywords)
{


}



filename[0] ->


METHOD 1 Brute force
TC : O(N^2) : N= length of the file_name

*/
