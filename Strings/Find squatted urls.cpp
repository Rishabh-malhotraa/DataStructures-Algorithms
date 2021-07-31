/*
OA for Palatir -- i should not put this on github LOL <But I don't suspect anyone would actually see this>
:: If someone does then Hi Stalked atleast drop a star at the repo lol

1 Subtask
  - Just check if the host name is differnt if domain name are (ignore if host name == host name of original)
  - Identify slightly differnt characters in the domain name
  - Identify if a swap has been made in the original company name and the fake company name 
    - subcase if palanti.rbiz is a TC of palantir.com because if . and first letter of the host are swapped 
      you are required to again run task one the same

How I Faired

- 1st task ALL TC Passed
    - {I got a WA because of using sets rather than multimap}
    - I took more time than I should have

- 2nd Task ALL TC Passed
    - I did took care of the case of nodes being underirected rather than directed i.e a -> {b, c} then b-> {a, c} & c-> {b ,a} 
    - I had a typo of 1 to l, but that did not take alot of time to figure out because I suspected 
      it to be an error in entry of map because I got just 1 WA for all TC

- 3rd Task
    - this was the easiest task but the second subpart took me alot of time to understand
      about what the question is actually saying
    - You need to just check if there was one swap
      - the second subpart was also very very easy
      - but i figured it out when I only had 3 minutes remaining & i legit found the last typo when I had 9 second remaining
      - not that it mattered much it just improved the tc by 1
      - I know why the other TC would have failed, what I suspect it is that I did not take case of duplicates
        I should have just  used a set and then a vector urghhhh
      - either that or there was some logic error but I doubt it.
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

vector<string> typosquats(vector<string> companyDomains, vector<string> newDomains)
{
  /* replacement
1 i l ! |
s 5 $
o 0
a @
e 3
*/

  unordered_map<char, set<char>> rp;
  rp['1'] = set<char>{'i', 'l', '!', '|'};
  rp['i'] = set<char>{'1', 'l', '!', '|'};
  rp['l'] = set<char>{'i', '1', '!', '|'};
  rp['!'] = set<char>{'i', 'l', '1', '|'};
  rp['|'] = set<char>{'i', 'l', '!', '1'};
  rp['s'] = set<char>{'5', '$'};
  rp['5'] = set<char>{'s', '$'};
  rp['$'] = set<char>{'5', 's'};
  rp['o'] = set<char>{'0'};
  rp['0'] = set<char>{'o'};
  rp['a'] = set<char>{'@'};
  rp['@'] = set<char>{'a'};
  rp['e'] = set<char>{'3'};
  rp['3'] = set<char>{'e'};

  vector<string> result;

  unordered_map<string, set<string>> real;
  set<string> names;
  bool flag = true;
  for (string cd : companyDomains)
  {
    int idx = cd.find('.');
    string name = cd.substr(0, idx);
    string domain = cd.substr(idx + 1);

    real[name].insert(domain);
    names.insert(name);
  }

  for (string s : newDomains)
  {
    int idx = s.find('.');
    string name = s.substr(0, idx);
    string domain = s.substr(idx + 1);

    if (real.find(name) != real.end() && real[name].find(domain) == real[name].end())
      result.push_back(s);
    else
    {
      // we need to check names here
      for (string cn : names)
      {
        if (cn.size() != name.size())
          continue;
        else
        {
          for (int i = 0; i < cn.size(); i++)
          {
            if (cn[i] == name[i] || (rp.find(cn[i]) != rp.end() && rp[cn[i]].find(name[i]) != rp[cn[i]].end()))
              flag = true;
            else
            {
              flag = false;
              break;
            }
          }
          if (flag == true && cn != name)
            result.push_back(s);
        }
      }
      // 3rd case [s is the name of the company
      for (string fn : companyDomains)
      {
        int count = 0;
        unordered_map<int, char> cache;
        if (fn.size() == s.size())
        {
          for (int i = 0; i < s.size(); i++)
          {
            if (fn[i] != s[i])
            {
              cache[i] = s[i];
              count++;
            }
          }
          if (count == 2)
          {
            result.push_back(s);
          }
        }
      }
      // last case
      int zind = s.find('.');

      string ns = s;

      swap(ns[zind], ns[zind + 1]);
      int idx = ns.find('.');
      string nname = ns.substr(0, idx);
      string ndomain = ns.substr(idx + 1);

      if (real.find(nname) != real.end() && real[nname].find(ndomain) == real[nname].end())
        result.push_back(s);
    }
  }

  /*
  to make all TC run do this I suspect this would solve but there could be a logic error too
  
  unordered_set<string> temp(result.begin(), result.end());
  result.clear();
  for (string res : temp)
    result.push_back(res);
  */

  return result;
}

#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}