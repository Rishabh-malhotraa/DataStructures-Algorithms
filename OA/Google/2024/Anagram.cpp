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
If you write the word "pod" in lower case and rotate it by 180 degrees (turning it upside-down by rotating), it looks exactly the same: "pod".
If you're a bit more flexible on how you write letters, the words "swims" and "yeah" do the same. These words are sometimes called ambigrams.
You are given a list of words, all written in lowercase.
Write a function that outputs all the words in the list that look the same when rotated, e.g., axe, dip, dollop, mow, ...

  ambigram
   is a work                  pod
                            ------- x=0
                             /////
                             dop          -> reverse  ->  pod


                             p
               sw             --


                             r
                            --
                             r'        ->  r'





  1. -> Replace every character with its mirro image
  2. -> revese the string

   3. -> if the string is same as the orignal string -> then we have ambigrams -> append it to the result

  r ->
  diction that

  */

class Ambigram
{
public:
  // { pod , swim}

  //
  // size of words -> N
  // Avergase size of each word -> M

  // Time complexity O(N*m)

  // Space complenxity -> O(N*m) + K
  vector<string> getAmbigrams(vector<int> &words)
  {

    unordered_map<char, char> dictionary = getDictionary();
    vector<string> ambigram;

    for (string word : words)
    {
      if (isStringAmbigram(word, dictionary))
      {
        ambigrams.push_back(word);
      }

      return ambigramn;
    }

  private:
    bool isStringAmbigram(string & word, unordered_map<char, char> & dictionary)
    {
      string mirrorWord = "";
      // assuming all the char to get a mirror image are in the dictionary
      for (char ch : word)
      {
        if (dictionary.find(ch) != dictionary.end())
          mirrorWord.push_back(dictionary[ch]);
        else
          return false;
      }

      reverse(mirrorWord.begin(), mirrorWord.end());

      return word == mirrorWord;
    }

    unordered_map<char, char> getDictionary()
    {
      unordered_map<char, char> dictionary = {
          {'b', 'p'},
          {'d', 'q'},
          ....

      };

      /*


      /*
     pod
       |

     mirrorWord = "dop" -> pod

          b
        --------
          p       |
                  |
                  |

      */

      return dictionary
    }
  };

  /*
  Write a function that outputs all the words that rotate to give a DIFFERENT word that is also in the list,
  input: loom (wool), wool...

  loom  wool

  */

  bool isStringAmbigram(string &word, unordered_map<char, char> &dictionary)
  {
    string mirrorWord = "";
    // assuming all the char to get a mirror image are in the dictionary
    for (char ch : word)
    {
      if (dictionary.find(ch) != dictionary.end())
        mirrorWord.push_back(dictionary[ch]);
      else
        return false;
    }

    reverse(mirrorWord.begin(), mirrorWord.end());

    return word == mirrorWord;
  }

  // word       - loom  ->
  // mirrorWord - wool

  result dictionary cache
      // Space complenxity -> O(N*m) + K            +  O(n*m)
      vector<string>
      getAmbigramsII(vector<int> &words)
  {
    unordered_map<char, char> dictionary = getDictionary();
    vector<string> result;

    unordered_set<string> cache(words.begin(), words.end());

    for (string word : words)
    {
      string mirrorWord = transform(word, dictionary);
      if (mirrorWord != word && cache.find(mirrorWord) != cache.end())
      {
        result.push_back(mirrorWord);
      }

      return result;
    }

    string transform(string & word, unordered_map<char, char> & dictionary)
    {
      string mirrorWord = "";
      // assuming all the char to get a mirror image are in the dictionary
      for (char ch : word)
      {
        if (dictionary.find(ch) != dictionary.end())
          mirrorWord.push_back(dictionary[ch]);
        else
          return "";
      }

      reverse(mirrorWord.begin(), mirrorWord.end());

      return mirrorWord;
    }

    string getAmbigramsII(string & words)
    {
      string result = "";
      unordered_map<char, char> dictionary = getDictionary();
      cache.insert(words);

      string mirrorWord = transform(word, dictionary);
      if (mirrorWord != word && cache.find(mirrorWord) != cache.end())
      {
        result = mirrorWord;
      }
      return result == "" ? null : mirrorWord;
    }
