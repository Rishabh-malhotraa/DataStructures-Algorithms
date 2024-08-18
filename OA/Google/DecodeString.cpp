
/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

/*
Questions given a string in the following format decode the given string

a(bcd)[3]e  -> abcdbcdbcde

a(b(cd){2}e(fg){3}){3} -> a bcdcd e fgfgfg bcdcdefgfgfg bcdcdefgfgfg


a(bcd)[3]e

  result = a + decodeString(s, 3) + e

a(b(cd){2}e(f(g){2}){3}){3}h
  

  result = a + decodeString(s,1) + h
                 b + decodeString(s,4) + e + decodeString(s,12)
                                                    decodeString((s,15))
                       
                
*/

#include <bits/stdc++.h>
using namespace std;

int getReplicationCount(string &s, int &i)
{
  string digit = "";
  i++; // for {
  for (; s[i] != '}'; i++)
    digit += s[i];
  i++; // for }
  return stoi(digit);
}

string getRelicatedString(string &s, int &replicationCount)
{
  string replicatedString = "";
  for (int i = 0; i < replicationCount; i++)
    replicatedString.append(s);
  return replicatedString;
}

string decodeString(string &s, int &idx)
{
  string result = "";
  int n = s.size();
  for (int i = idx; i < n; i++)
  {

    if (s[i] == '(')
    {
      result = result + decodeString(s, ++i);
    }
    else if (s[i] == ')')
    {
      int replicationCount = getReplicationCount(s, ++i);
      return getRelicatedString(result, replicationCount);
    }

    if (i < n)
      result.push_back(s[i]);
  }

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

  string s;
  int idx = 0;
  cin >> s;
  cout << decodeString(s, idx) << endl;
  return 0;
}