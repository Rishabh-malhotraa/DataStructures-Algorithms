//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Easy just map characters to letter and then search thorugh the entire search space

class Solution
{
public:
  vector<string> result;
  unordered_map<char, string> umap;

  void backtrack(int start, string digits, string currStr)
  {
    int n = digits.size();
    if (start == n)
      result.push_back(currStr);
    else
    {
      char ch = digits[start];
      string val = umap[ch];

      for (int i = 0; i < val.size(); i++)
        backtrack(start + 1, digits, currStr + val[i]);
    }
  }

  vector<string> letterCombinations(string digits)
  {
    umap.insert({'2', "abc"});
    umap.insert({'3', "def"});
    umap.insert({'4', "ghi"});
    umap.insert({'5', "jkl"});
    umap.insert({'6', "mno"});
    umap.insert({'7', "pqrs"});
    umap.insert({'8', "tuv"});
    umap.insert({'9', "wxyz"});

    if (digits.size() > 0)
      backtrack(0, digits, "");
    return result;
  }
};