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

1. Convert every letter to its ASCII value.
2. Add 1 to the first letter, and then for every letter from the second one to the last one, add the value of the previous letter.
3. Subtract 26 from every letter until it is in the range of lowercase letters a-z in ASCII. Convert the values back to letters.


a -> [96 + 1]

 C     R        I      M E
[96+3] [96+]    [96+9]
  Z     R     I    M    E
  122 	 114   105  109  101   step -1
  123  214   319  428  529   step-2      a - z  | 97 - 122
  97  110   111  116  113   || -->  dnotq    ---> crime

d - [notq] ->  c - []



C R I M E



D N O T Q



ency [D-1]  [N-D] + 26


second character ->     97 <=  [value + C] - x(26)  <= 122



'N'  =  [x + c +1] - 26y

110 =  100 + [x] - 26y

10 + 26y = x

y = 1, 2, 3, 4, 5,

10 + 26
10 + 52
10 + 78
10 + 104 => 114

  10   =  x - 26x

   97  < (D - N) + 26x   <  122



10 + 26z = x


the value of x lies between 97 -- 122

  R ->

  R   =    R + 'C'
newValue[i] = str[i] + newValue[i-1];



Step 1:   Base case decrpt[0] = (encrypt[0] - 1  + 26)%26


Step 2:  decrypt[1]  =  decrypt[1] - decrypt[0]
         Keep adding 26 until in range of 97 - 122
         Once we are in the range we know out answer

Step 3 : incrementally built the solution


TC: O(N)
SC: O(1)


*/

string decrypt(const string &word)
{

  string code = word;

  char firstCharacter = (word[0] == 'a') ? 'z' : word[0] - 1;

  code[0] = firstCharacter;

  int n = word.size();
  for (int i = 1; i < n; i++)
  {
    int key = word[i] - word[i - 1];

    int a = (int)'a';
    int z = (int)'z';

    while (!(key >= a && key <= z))
      key += 26;

    code[i] = (char)key;
  }

  return code;
}

int main()
{
  return 0;
}