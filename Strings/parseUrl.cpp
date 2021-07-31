/*
 ____  _     _           _     _       __  __       _ _           _             
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _ 
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// #include <sstream>
// using string stream (delimeter has to be a charater)
void parseDomain(string d)
{
  string domain;
  d.push_back('.');
  stringstream domains(d);
  while (getline(domains, domain, '.'))
    cout << domain << " ";
  d.pop_back();
  cout << endl;
  return;
}

// using library function delimeter can be a string!
void parseDomainII(string d)
{
  string delimeter = ".";
  int start = 0;
  int end = d.find(delimeter);
  d.push_back('.');
  while (end != string::npos)
  {
    // you can add logic of www | ww2 or web
    cout << d.substr(start, end - start) << " ";
    start = end + delimeter.size();
    end = d.find(delimeter, start);
  }
  d.pop_back();
  cout << endl;
}

// Basic Logic using a for loop
void explode(string d)
{
  string token;
  d.push_back('.');
  for (char ch : d)
  {
    if (ch == '.')
    {
      if (token != "www" && token != "ww2" && token != "web")
      {
        cout << token << " ";
        token.clear();
      }
    }
    else
      token += ch;
  }
  d.pop_back();

  cout << endl;
}

void solve()
{
  string url;
  cin >> url;

  int idx = url.find("://"), n = url.size();
  string protocol = url.substr(0, idx);
  int start = idx + 3;

  int end = url.find('/', start) == string::npos ? n : url.find('/', start);

  string domain = url.substr(start, end - start);

  string path = url.substr(end);

  /*
  parseDomain(domain);
  parseDomainII(domain);
  explode(domain);
  */

  cout << protocol << endl;
  cout << domain << endl;
  cout << path << endl;

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