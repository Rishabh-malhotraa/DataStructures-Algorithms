/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// Strings Manupilation
// Smart way to deal with `-` in the begining is start the find from idx 1

class Solution
{
private:
  pair<int, int> extract(string num)
  {
    int idx = num.find('+', 1);
    int real = stoi(num.substr(0, idx));
    string temp = num.substr(idx + 1);
    temp.pop_back();
    int img = stoi(temp);
    return {real, img};
  }

public:
  string complexNumberMultiply(string num1, string num2)
  {
    pair<int, int> a = extract(num1);
    pair<int, int> b = extract(num2);

    int real = a.first * b.first - a.second * b.second;
    int img = a.first * b.second - a.second * b.first;

    return to_string(real) + '+' + to_string(img) + 'i';
  }
};