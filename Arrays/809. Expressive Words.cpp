//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Cisco OA 5-8-21 on campus
// Easy-Medium | HashMap | Arrays

class Solution
{
public:
  vector<pair<char, int>> createList(string word)
  {
    vector<pair<char, int>> wordList;

    char prev = word[0];
    int idx = 0;
    wordList.push_back({prev, 1});
    for (int i = 1; i < word.size(); i++)
    {
      char curr = word[i];
      if (curr == prev)
      {
        wordList.back().second++;
      }
      else
      {
        wordList.push_back({curr, 1});
        prev = curr;
      }
    }
    return wordList;
  }
  int expressiveWords(string word, vector<string> &words)
  {
    vector<pair<char, int>> wordList = createList(word);
    int result = 0;
    for (string str : words)
    {
      auto checkList = createList(str);
      if (checkList.size() != wordList.size())
        continue;
      else
      {
        bool flag = true;
        for (int i = 0; i < wordList.size(); i++)
        {
          pair<char, int> p1 = wordList[i];
          pair<char, int> p2 = checkList[i];

          if (p1.first != p2.first)
          {
            flag = false;
            break;
          }
          else
          {
            int freq1 = p1.second;
            int freq2 = p2.second;

            if (freq1 > freq2)
            {
              int delta = freq1 - freq2;
              if (delta + freq2 < 3)
              {
                flag = false;
                break;
              }
            }
            else if (freq1 == freq2)
            {
              continue;
            }
            else
            {
              flag = false;
              break;
            }
          }
        }
        if (flag == true)
          result++;
      }
    }
    return result;
  }
};