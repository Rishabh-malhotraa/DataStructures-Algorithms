/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// https://www.cplusplus.com/reference/string/string/append/
// go through this link for member functions of string

// 0. stringstream
// 1. +=  || find || substr
// 2. push_back() || pop_back()
// append || insert || erase
class Playground
{
private:
  string s;

public:
  Playground(string s)
  {
    this->s = s;
  }

  int Find()
  {
    char character = 'a';
    string substring = "ish";
    // find a charcter Or a Substring;
    if (s.find('a') != string::npos)
      cout << s.find('a') << endl;

    if (s.find(substring) != string::npos)
      cout << s.find(substring) << endl;
  }

  void Insert(int idx, string target)
  {

    string str = "to be question";
    string str2 = "the ";
    string str3 = "or not to be";
    string::iterator it;

    // used in the same order as described above:
    str.insert(6, str2);                   // to be (the )question
    str.insert(10, "that is cool", 8);     // to be not (that is )the question
    str.insert(10, "to be ");              // to be not (to be )that is the question
    str.insert(15, 2, ':');                // to be not to be(::) that is the question
                                           //
    it = str.insert(str.begin() + 5, ','); // to be(,) not to be: that is the question
    str.insert(str.end(), 3, '.');         // to be, not to be: that is the question(...)

    cout << str << '\n';

    s = s.insert(idx, target);
  }

  void Assign(string str, string base)
  {
    str = "";
    base = "The quick brown fox jumps over a lazy dog.";

    str.assign(base); // str =  "The quick brown fox jumps over a lazy dog."

    str.assign(base, 10, 9);            // BASE | start | n
    cout << str << '\n';                // "brown fox"
    str.assign("pangrams are cool", 7); // BASE | n
    cout << str << '\n';                // "pangram"
    str.assign("c-string");
    cout << str << '\n'; // "c-string"

    str.assign(10, '*');
    cout << str << '\n';
  }

  void append()
  {
  }

  void operations()
  {
    int idx, start_pos, n;
    string target;

    s = s.insert(idx, target);

    target = s.substr(start_pos, n);
  }
};

void solve()
{
  string s;
  cin >> s;

  Playground *sol = new Playground(s);

  sol->operations();
}

int main()
{
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