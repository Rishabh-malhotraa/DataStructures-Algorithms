/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/
// I got the same question for Booking.com test LOL
#include <bits/stdc++.h>
using namespace std;

string simpleCipher(string encrypted, int k)
{
  k = k % 26;
  string decrypted = encrypted;

  for (char &character : decrypted)
  {
    int idx = character - 'A';
    int shift = (idx - k + 26) % 26;
    character = (char)('A' + shift);
  }
  return decrypted;
}