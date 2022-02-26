#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimalDestruction' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY heights as parameter.
 */

int minimalDestruction(vector<int> heights)
{
  int n = heights.size();
  sort(heights.begin(), heights.end());

  vector<long long> suffix(n + 1, 0);

  for (int i = n - 1; i >= 0; i--)
    suffix[i] = suffix[i + 1] + heights[i];

  long long minCost = LONG_LONG_MAX, rodsDestroyed = 0;
  for (int i = 0; i < n; i++)
  {
    int k = n - i;

    long long currCost = rodsDestroyed + (suffix[i] - heights[i] * k);

    minCost = min(minCost, currCost);

    rodsDestroyed += heights[i];
  }

  return minCost;
}
/*
int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string heights_count_temp;
  getline(cin, heights_count_temp);

  int heights_count = stoi(ltrim(rtrim(heights_count_temp)));

  vector<int> heights(heights_count);

  for (int i = 0; i < heights_count; i++)
  {
    string heights_item_temp;
    getline(cin, heights_item_temp);

    int heights_item = stoi(ltrim(rtrim(heights_item_temp)));

    heights[i] = heights_item;
  }

  int result = minimalDestruction(heights);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
*/