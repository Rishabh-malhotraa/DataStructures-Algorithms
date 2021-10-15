
#include <bits/stdc++.h>
using namespace std;
int mod_inverse(int k)
{
  for (int i = 0; i < 26; i++)
  {
    int flag = (i * k) % 26;
    if (flag == 1)
      return i;
  }
  return -1;
}

string decrypt(string cipher_text, int key1, int key2)
{
  string message = "";
  int key_inverse = mod_inverse(key1);
  if (key_inverse == -1)
    return "Not exist";

  for (int i = 0; i < cipher_text.size(); i++)
    message += char(((((cipher_text[i] - 'A' - key2) % 26 + 26) % 26) * key_inverse) % 26 + 'A');

  return message;
}

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int key1 = 9, key2 = 7;
  string cipher_text = "HYFEJZ";

  cout << "Mesage: " << cipher_text << endl;
  cout << "Decrypted Message: " << decrypt(cipher_text, key1, key2) << endl;
}