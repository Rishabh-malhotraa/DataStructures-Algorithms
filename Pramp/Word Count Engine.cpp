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


Perfect practice

 If two or more words have the same count, they should be sorted according to their order in the original sentence.
 practice 2
 perfect 2


                        1       2       3
                    | Practice perfect perfect|
input:  document = "Practice makes perfect. you'll only
                    get Perfect by practice. just practice!"

output: [ ["practice", "3"], ["perfect", "2"],
          ["makes", "1"], ["youll", "1"], ["only", "1"],
          ["get", "1"], ["by", "1"], ["just", "1"] ]


1.  sort based on count (DESCENDING)         sort in lexicographical order ->
2.  ordering in the sentence
3.  The engine should strip out punctuation (even in the middle of a word) and use whitespaces to separate words.



you.are
youare

you are
you are
you. are
you are


puntuatuib -> . ,

you'll  -> youll



=> abcc bdd


Method 1 : Linear Scanning of our document

        |     |
Practice ya'll perfect.

word = Pra


store

Time COmplexity :  O(nlogn)
Space COmplexity: O(N)
*/

using namespace std;

string process(string token)
{
  string word;
  for (int i = 0; i < token.size(); i++)
  {

    char ch = token[i];
    // 1. remove everything except alphabets
    // 2. everything to lowever case ==> Practice -> practice

    // a => 65
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
      if (ch >= 'A' & ch <= 'Z')
        ch = (char)('a' + (ch - 'A'));

      word.push_back(ch);
    }
  }
  cout << word << endl;
  return word;
}

unordered_map<string, int> position;

// return something

// sentence : b a b a return b2 a2  |
// c b b a return b2 c1 a1

static bool compare(vector<string> &a, vector<string> &b)
{
  int v1 = stoi(a[1]);
  int v2 = stoi(b[1]);

  // a[0]-> word  a[1] -> count
  if (v1 == v2)
    return position[a[0]] < position[b[0]];

  return v1 > v2;
}

vector<vector<string>> wordCountEngine(const string &_d)
{
  string document = _d;
  position.clear();
  stringstream ss(document);

  unordered_map<string, int> cache;
  string token;
  int idx = 0;
  while (getline(ss, token, ' '))
  {
    if (token == "")
      continue;
    string word = process(token);

    position.insert({word, idx}); // what insert does is
    cache[word] += 1;
    idx++;
  }

  vector<vector<string>> result;

  for (pair<string, int> el : cache)
  {
    result.push_back({el.first, to_string(el.second)});
  }

  sort(result.begin(), result.end(), compare);

  return result;
  // your code goes here
}

int main()
{
  return 0;
}