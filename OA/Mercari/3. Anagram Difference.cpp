#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getMinimumDifference' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY a
 *  2. STRING_ARRAY b
 */

const int ALPHABET_SIZE = 26;

int getKey(char &ch)
{
  return (int)(ch - 'a');
}

int calculateDifference(string &s1, string &s2)
{
  vector<int> frequency(ALPHABET_SIZE, 0);
  int key = 0, difference = 0;
  if (s1.size() != s2.size())
    return -1;
  else
  {
    for (char &ch : s1)
    {
      key = getKey(ch);
      frequency[key]++;
    }

    for (char &ch : s2)
    {
      int key = getKey(ch);
      frequency[key]--;

      if (frequency[key] < 0)
        difference++;
    }
  }
  return difference;
}

vector<int> getMinimumDifference(vector<string> a, vector<string> b)
{
  vector<int> result;
  int n = a.size();
  for (int i = 0; i < n; i++)
    result.push_back(calculateDifference(a[i], b[i]));

  return result;
}
