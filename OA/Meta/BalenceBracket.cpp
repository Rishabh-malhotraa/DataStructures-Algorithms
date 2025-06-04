
#include <vector>
#include <unordered_map>
#include <iostream>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

using namespace std;


/* """
You are given a square grid of size N, where N>=3. I have placed a battleship
of size 3 somewhere in the grid, and you want to sink my battleship by
ordering the bombing of specified coordinates. The battleship can only be
placed vertically or horizontally, not diagonally.
Every coordinate which does not contain the battleship is empty.

Your task is to write the find_battleship function which takes N as input, and returns the 3 coordinates of the battleship.
Assume you have a function, boolean bomb_location(x, y), which will return True if (x, y) "hits" the battleship and False if (x, y) misses the battleship.

For example, in the following grid your function find_battleship(N),
given N of 8,  would return ((1,2), (2,2), (3,2)):

. . . . . . . .
. . X . . . . .
. . X . . . . .
. . X . . . . .
. . . . . . . .
. . . . . . . .
. . . . . . . .
. . . . . . . .


. . . . . . . .
. . X . . . . .        X
. . X . . . . .
. . X . . . X .
. . . . . . X .
. . . . . . . .
. . . . . . . .
. . . . . . . .
""" */

/*
TC:: O(N*N)
SC : O(1)

*/

bool bomb_location(int i, int j);

bool isValid(int i, int j, int n) {
  return (i >= 0 && i < n && j >= 0 && j < n);
}

vector<pair<int, int>> placeBattleShip(int N) {

  int pos = rand() % (N * N);

  int i = pos / N, j = pos % N;

  vector<pair<int, int>> dir{
    {0,1},  // right
    {0,-1}, // left
    {1,0},  // up 
    {-1,0} // down
  };

  vector<pair<int, int>> coordinates{ {i,j} };
  for (auto [di, dj] : dir) {

    for (int idx = 0; idx < 2; idx++) {
      int ni = i + di, nj = j + dj;
      if (isValid(ni, nj, N)) {
        coordinates.push_back({ ni,nj });
      }
    }

    if (coordinates.size() == 3)
      return coordinates;
    else
      coordinates.erase(coordinates.begin() + 1, coordinates.end());
  }
  return {};
}

vector<pair<int, int>> getCoordinates(int N) {

  vector<pair<int, int>> coordinates;
  for (int i = 0; i < N; i++) {
    if (coordinates.size() == 3)
      break;

    for (int j = 0; j < N; j++) {
      if (coordinates.size() == 3)
        break;

      if (bomb_location(i, j)) {
        coordinates.push_back({ i, j });
      }
    }
  }
  return coordinates;
}


// vector<pair<int, int>> getCoordinates(int N) {

//   vector<pair<int, int>> coordinates;
//   for (int i =0; i < N * N; i++) {    
//     if (coordinates.size() == 3)
//         break;

//     // int x = i/n, y = i%n; 

//     if (bomb_location(i,j)) {
//         coordinates.push_back(i,j)
//       }
//   }
//   return coordinates;
// }





bool isBracketFunc(char ch) {
  string Bracket = "({[<>>]})";
  return Bracket.find(ch) != string::npos;
}

bool isCloseBracketFunc(char ch) {
  // we try to find [
  string closebrackets = ")}]>";
  return closebrackets.find(ch) != string::npos;
}

/*
TC: O(N)
SC: O(N)  }]]][[[{
*/
bool balenceBrackets(string s) {
  unordered_map<char, int> getOpenBracket{
    {')', '(' },
    {'}', '{' },
    {']', '[' },
    {'>', '<' },
  };
  // if (ch == '(' || ch == '{'  || ch == "[" || ch == '<')

  stack<char> brackets;
  string closebrackets = ")}]>";

  for (char ch : s) {

    auto idx = closebrackets.find(ch);

    bool isBracket = isBracketFunc(ch);
    bool isCloseBracket = isCloseBracketFunc(ch);


    if (isCloseBracket) {
      if (!brackets.empty() && brackets.top() == getOpenBracket[closebrackets[idx]])
        brackets.pop();
      else
        brackets.push(ch);
    }
    else if (isBracket) {
      brackets.push(ch);
    }
  }
  return brackets.size() == 0;
}

/*

[]



abcd(egf))"


"[abcdef"


]

bracketType[closebrackets[idx]]


               |
[abc(def)gh{i}j]


*/

/*
      } else if (isCloseBracket && (brackets.empty() || brackets.top() != bracketType[closebrackets[idx]])){
      {
        return false;
      } else if (isBracket && !isCloseBracket){
          bracket.push(ch);
      }
*/




// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const char* const& word : words) {
    cout << word;
  }
  return 0;
}


// Your previous Plain Text content is preserved below:

// Welcome to Meta!

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you would like to use for your interview,
// simply choose it from the dropdown in the left bar.

// Enjoy your interview!