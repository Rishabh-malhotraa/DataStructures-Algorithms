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
move character by  k places in counter clockwise direction
*/

string simpleCipher(string encrypted, int k)
{
  string cipher = encrypted;
  k = k % 26;

  for (int i = 0; i < cipher.size(); i++)
  {
    int key = cipher[i] - 'A';
    cipher[i] = (char)('A' + ((key - k + 26) % 26));
  }

  return cipher;
}