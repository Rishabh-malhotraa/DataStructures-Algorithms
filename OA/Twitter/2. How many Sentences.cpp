#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countSentences' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY wordSet
 *  2. STRING_ARRAY sentences
 */

vector<long> countSentences(vector<string> wordSet, vector<string> sentences)
{
  unordered_map<string, int> cache;
  unordered_map<string, int> count;

  vector<long> result;

  for (string &word : wordSet)
  {
    string temp = word;
    sort(temp.begin(), temp.end());
    cache[temp]++;
  }

  for (string &word : wordSet)
  {
    string temp = word;
    sort(temp.begin(), temp.end());
    count[word] = cache[temp];
  }

  for (string sentence : sentences)
  {
    long curr_answer = 1;
    stringstream ss(sentence);
    char delimeter = ' ';
    string token;

    while (getline(ss, token, delimeter))
      curr_answer *= count[token];

    result.push_back(curr_answer);
  }

  return result;
}