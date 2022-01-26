/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestPalindrome(vector<string> &words)
  {
    bool occupied = false;
    unordered_map<string, int> freq;
    int maxLen = 0;

    for (string word : words)
      freq[word]++;

    // for(auto [word, count] : freq)
    // {
    //   cout << word << " " << count << endl;
    // }

    for (auto [word, count] : freq)
    {
      // cout << word << endl;
      string reverseWord = word;
      reverse(reverseWord.begin(), reverseWord.end());
      // cout << maxLen << " " << word  << endl;
      if (word[0] == word[1])
      {
        maxLen += 4 * (count / 2);
        if (count % 2 == 1 && occupied == false)
        {
          maxLen += 2;
          occupied = true;
        }
      }
      else if (freq.count(reverseWord))
      {
        int c = min(freq[reverseWord], freq[word]);
        freq[reverseWord] -= c;
        freq[word] -= c;
        maxLen += c * 4;
      }
    }
    return maxLen;
  }
};