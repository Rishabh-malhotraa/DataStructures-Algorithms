#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'hackerCards' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY collection
 *  2. INTEGER d
 */

vector<int> hackerCards(vector<int> nums, int d) {
  set<int> s(nums.begin(), nums.end());
  vector<int> result;
  int sum = 0;
    for(int i = 1 ; i <= d ; i++)
    {
        if(i + sum > d)
        {
          break;
        }
      if(s.find(i) == s.end())
      {
        sum += i; 
        result.push_back(i);
      } 
    }
  return result;
}
