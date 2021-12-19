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
  string numberToWords(int n)
  {
    return n ? toWords(n).substr(1) : "Zero";
  }

private:
  vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  string toWords(int n)
  {
    if (n >= 1000000000)
    {
      return toWords(n / 1000000000) + " Billion" + toWords(n % 1000000000);
    }
    if (n >= 1000000)
    {
      return toWords(n / 1000000) + " Million" + toWords(n % 1000000);
    }
    if (n >= 1000)
    {
      return toWords(n / 1000) + " Thousand" + toWords(n % 1000);
    }
    if (n >= 100)
    {
      return toWords(n / 100) + " Hundred" + toWords(n % 100);
    }
    if (n >= 20)
    {
      return " " + tens[n / 10] + toWords(n % 10);
    }
    if (n >= 1)
    {
      return " " + ones[n];
    }
    return "";
  }
};