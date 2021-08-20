#include <bits/stdc++.h>

using namespace std;

/*

Method 1:(Brute force)
to take all substring of size atleast arr.sized()
and find if it contains all the elements of arr
and see if its present

xyyzyzyx
[arr.size()* arr.size()-1 ....*1] 

Method 2: Sliding Window

- Time Complexity O(N)

string =  xyyzyzyx
              |
           
         ns = xyyz => result = 4     
step II  ns = yyz + 'yzyx'  => result
step III  =>  yyzyzyx
               yx  result = 3  
*/

bool doesMatch(string &ns, unordered_map<char, int> keys)
{

  for (char ch : ns)
  {
    if (keys.count(ch))
      keys[ch]--;
  }

  for (auto el : keys)
    if (el.second > 0)
      return false;

  return true;
}

string getShortestUniqueSubstring(vector<char> &arr, const string &s)
{
  unordered_map<char, int> cache;

  // Inserting of arr to hash map
  for (char &ch : arr)
  { // O(1)
    cache[ch] += 1;
  }
  // O(arr.size())

  string shortestString;
  int n = s.size(); // size of our string to be searched
  int curr = 0;
  string ns;
  int result = INT_MAX;

  /*
  DRY RUN
  arr = ['x','y','z'], str = "xyyzyzyx"
  
  x = 1
  y = 1
  z = 1
  
  ns = "" -> "x" -> "xy" => "xyyz"
  str =  "xyyzyzyx"
  curr = 0
  n = 8
  result = 4
  shortestString  = "xyyz"
  
  */

  while (curr < n) // O(M)
  {
    if (doesMatch(ns, cache)) //  O(M) -> O(1)
    {
      if (result > ns.size())
      {
        result = ns.size(); // space complexity O(M)
        shortestString = ns;
      }

      while (!ns.empty() && doesMatch(ns, cache))
        ns = ns.substr(1);
    }
    else
    {
      ns.push_back(s[curr]);
    }
  }
  return shortestString;
}

int main()
{
  return 0;
}