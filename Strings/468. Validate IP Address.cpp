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
  vector<string> getTokens(string s, char delimeter)
  {
    stringstream ss(s);
    vector<string> tokens;
    string token;
    while (getline(ss, token, delimeter))
      tokens.push_back(token);

    return tokens;
  }

  bool isNumber(string s)
  {
    for (char ch : s)
      if (isdigit(ch) == false)
        return false;
    return true;
  }

  bool isHexadecimal(string s)
  {
    for (char ch : s)
      if (isxdigit(ch) == false)
        return false;
    return true;
  }

  bool trailingZeroes(string s)
  {
    return (s.front() == '0' && s.size() != 1) ? true : false;
  }

  bool checkIPv4(string ip)
  {
    vector<string> tokens = getTokens(ip, '.');
    if (tokens.size() != 4 || ip.back() == '.')
      return false;

    for (string token : tokens)
    {
      if (token == "")
        return false;

      bool isNum = isNumber(token);

      if (isNum == false || token.size() > 3 || trailingZeroes(token))
        return false;

      int num = stoi(token);

      if (num > 255)
        return false;
    }
    return true;
  }

  bool checkIPv6(string ip)
  {
    vector<string> tokens = getTokens(ip, ':');
    if (tokens.size() != 8 || ip.back() == ':')
      return false;

    for (string token : tokens)
    {
      if (token == "")
        return false;

      bool isHexa = isHexadecimal(token);

      if (!isHexa || token.size() > 4)
        return false;
    }
    return true;
  }

public:
  string validIPAddress(string queryIP)
  {
    bool isIPv4 = checkIPv4(queryIP);
    bool isIPv6 = checkIPv6(queryIP);

    return isIPv4 ? "IPv4" : isIPv6 ? "IPv6"
                                    : "Neither";
  }
};