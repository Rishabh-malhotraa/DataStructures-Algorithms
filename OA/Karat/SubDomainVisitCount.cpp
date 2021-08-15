//  ____  _     _           _     _       __  __       _ _           _
// |  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
// | |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
// |  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
// |_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

#include <bits/stdc++.h>
using namespace std;

// Easy Hashmaps string questions

class Solution
{
public:
  vector<string> subdomainVisits(vector<string> &cpdomains)
  {
    unordered_map<string, int> cache;
    vector<string> result;
    for (string &domain : cpdomains)
    {
      int idx = domain.find(' ');

      int count = stoi(domain.substr(0, idx));
      string name = "." + domain.substr(idx + 1);

      idx = name.find(".");
      while (idx != string::npos)
      {
        string token = name.substr(idx + 1);
        cache[token] += count;
        idx = name.find(".", idx + 1);
      }
    }

    for (pair<string, int> el : cache)
      result.push_back(to_string(el.second) + " " + el.first);

    return result;
  }
};