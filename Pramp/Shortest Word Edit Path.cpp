/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// https//github.com/MysteryVaibhav/leetcode_company_wise_questions

/*

1. insert the source word in the queue
while
  2. find neighbours of this word -> [all the words in words that difffer just by one character]
  3. we insert those neighbours in the queue
  4. if the curr word = q.front() == target => steps
5. -1 


*/

int getDiff(string s1, string s2) // m
{
  if (s1.size() != s2.size())
    return -1;

  int count = 0;
  for (int i = 0; i < s1.size(); i++)
    if (s1[i] != s2[i])
      count++;

  return count;
}

vector<string> getNeighbours(string &target, vector<string> words) // N
{
  vector<string> result;
  for (string word : words)
    if (getDiff(word, target) == 1)
      result.push_back(word);

  return result;
}

// len(words) * len(word)^2

int shortestWordEditPath(const string &source, const string &target, const vector<string> &words)
{
  queue<pair<string, int>> q; // O(n) Space
  q.push({source, 0});

  unordered_map<string, bool> visited; // O(N) Space COmplexity

  // O(V+E)
  while (q.empty() == false)
  {
    //    auto &[word, distance] = q.front();

    string word = q.front().first;
    int distance = q.front().second;

    visited[word] = true;
    q.pop();

    if (word == target)
      return distance;

    // O(N*ni)
    // n = word.size()  -> ni = word[i].size()
    // N * (n*n)
    // O((N^2)*m)

    vector<string> neighbours = getNeighbours(word, words); // O(N*ni)

    for (string neighbour : neighbours)
      if (visited[neighbour] == false)
        q.push({neighbour, distance + 1});
  }

  return -1;
  // your code goes here
}

int main()
{
  return 0;
}

// [bit]  -> but ->  2[cut]   -  [5]
/*                    [dut]   -- [3]

[bit] -> [but] ->  {[put], [cut] , [dut] } 

source = "bit", target = "dog"
words = ["but", "put", "big", "pot", "pog", "dog", "lot"]


bit -> but -> put -> pot -> dog

output: 5
explanation: bit -> but -> put -> pot -> pog -> dog has 5 transitions.

*/