/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  This is the Master's API interface.
 *  You should not implement it, or speculate about its implementation
 **/
class Master
{
public:
  int guess(string word);
};

class Solution
{
public:
  vector<string> getPruneList(vector<string> &wordlist, string checkWord, int matches)
  {
    vector<string> pruneList;
    for (string word : wordlist)
    {
      int count = 0;
      for (int i = 0; i < word.size(); i++)
        if (checkWord[i] == word[i])
          count++;

      if (count == matches)
        pruneList.push_back(word);
    }
    return pruneList;
  }

  void findSecretWord(vector<string> &wordlist, Master &master)
  {
    for (int i = 0; i < 10; i++)
    {
      string randomWord = wordlist[rand() % (wordlist.size())];
      int matches = master.guess(randomWord);
      wordlist = getPruneList(wordlist, randomWord, matches);
    }
  }
};