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

Write a function that supports substitution of a wildcard (represented by ‘%’) with a string.
For example, Substitute(“Hello %!”, “world”) should return “Hello world!”.

Hello %!

  we have to substitue the % -> world

-->   X
Hello %!World
         <-------

TC: O(N)
SC: O(1)



       |
Hello %!

newText = Hello world!


capcity -> 10
amortized O(1) O(N)

O(m)

*/

string replaceWord(string &text, string &replace)
{
  // text[i] = 'A'
  int n = text.size();
  string newText = "";
  for (int i = 0; i < n; i++)
  {
    if (text[i] == '%')
    {
      newText += replace;
    }
    else
    {
      newText += text[i];
    }
  }
  return newText;
}

/*
Write a tool that supports substitution of strings by other strings.
For example, if CITY = “Zurich” and COUNTRY = “Switzerland”, we want
the string “Welcome to %CITY%, %COUNTRY%!” to resolve to “Welcome to Zurich, Switzerland!”.

Welcome to %CITY%, %COUNTRY%!”
           |----|
'%' ---- %

unordered_map<string, string> valueMap


valueMap["CITY"]="Zurich"





Welcome to %CITY%, %COUNTRY%!”
                |

key="CITY"

i=

newText = Welcome to
*/

string replaceWord(string &text, unordered_map<string, string> &cache)
{
  int n = text.size();
  string newText = "";
  int i = 0;
  while (i < n)
  {
    if (text[i] == '%')
    {
      string key = "";
      // %CITY%
      //    |
      // CIT
      while (text[++i] != '%')
      {
        key.push_back(text[i]);
      }
      newText += cache[key]; // O(1) IN CASE OF COLLISION O(N)
      i++;                   //
    }
    else
    {
      newText += text[i];
      i++;
    }
  }
  return newText;
}

/*
cache[City] -> Zurich, %COUNTRY%

The tool should now also support recursive substitutions.

For example, if CITY = “Zurich, %COUNTRY%” and COUNTRY = “Switzerland”,
we want the string “Welcome to %CITY%!” to resolve to “Welcome to Zurich, Switzerland!”.


Another example: if USER = “jim” and HOME = “/home/%USER%”, then “%HOME%/storage/”
should again expand to “/home/jim/storage”.


USER = "JIM"

home => /home/jim




A -> B -> A
if we want to find

topological sorting

DAG -- there is no cycle

A


indegrees




*/

class ReplaceWords
{
private:
  unordered_map<string, string> cache;

  void preComputeCache()
  {
  }

public:
  ReplaceWords(unordered_map<string, string> &cache)
  {
    this->cache = cache;
    preComputeCache();
  }

  string replaceText(string text)
  {
    // we substitute the text using our precomputed cache
  }
};

// How i would strucute it after giving some thought to it

class ReplaceWords
{
private:
  unordered_map<string, string> cache;
  vector<string> sortedDependecies;
  bool computed, acyclic;

  void resolveDependecies()
  {
    // resolve dependencies using sortedDependecies vector which is topologically sorted
  }

  unordered_map<string, list<string>> buildGraph()
  {
  }

  bool isAcyclic()
  {
    if (computed) // cached value
      return acyclic;

    // check if graph is DAG using Kahns Algorithm (indegrees)
    unordered_map<string, list<string>> graph = buildGraph();
  }

public:
  ReplaceWords(unordered_map<string, string> &cache)
  {
    this->cache = cache;
    computed = acyclic = false;
  }

  void newCache(unordered_map<string, string> cache)
  {
    this->cache = cache;
    computed = acyclic = false;
    init();
  }

  void init()
  {
    if (isAcyclic() == true)
      resolveDependecies();
    else
      throw invalid_argument("cyclic dependecies");
  }

  string replaceText(string &text)
  {
    if (isAcyclic() == false)
      return "";

    // we substitute the text using our precomputed cache
  }
};
