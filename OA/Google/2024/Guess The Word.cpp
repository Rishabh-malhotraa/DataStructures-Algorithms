/*


std::vector<std::string> words = {};
std::string Guess(const std::string& word);

The word that you are trying to guess is "tires"
Guess 1: apple Returns: ---e-
Guess 2: tales Returns: t--es
Guess 3: times Returns: ti-es
Guess 4: steer Returns: t-res
Guess 5: tires Returns: tires

frewq


guess(apple) -> ---e-


mash -> 19

  <Hash>  <>                                      X
{ apple, tales, times, steer, tires, banan}
  *        *
fuzzy


a -> 3
l -> 2

apple -> aelpp
         aelst
         eerts
         eirsr
         aabnn

*/

/*

cost of a guess  -> 1000
clock -> 10/per second


have as much money as possible when you reach the correct guess

*/

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

std::string Guess(const std::string &word);

class Timer
{
public:
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
  std::chrono::duration<float> duration;
  Timer()
  {
    start = std::chrono::high_resolution_clock::now();
  }
  ~Timer()
  {
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    float ms = duration.count() * 1000.0f;
    cout << " Code executed in " << ms << "ms " << endl;
  }

  float getTimeFromStart(std::chrono::time_point<std::chrono::high_resolution_clock> now)
  {
    std::chrono::duration<float> duration = now - start;
    return duration.count() * 1000.0f;
  }
};

int cost(vector<string> &words, int money)
{
  int COST_OF_GUESS = 1000;
  int COST_PER_MILLI_SECOND = 10;
  Timer time;
  // { apple, tales, times, steer, tires, banan}

  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> options;
  unordered_map<char, int> freq = getFrequencyMap(words);

  for (string word : words)
    options.push({getValue(word, freq), word});

  string guessWord = "_____";

  while (!(guessWord.find('_') == string::npos) || money == 0)
  {
    string bestPick = options.top().second;
    options.pop();
    // a___b  besta
    bool check = checkIfBestPickIsValid(bestPick, guessWord);

    money -= time.getTimeFromStart(chrono::high_resolution_clock::now()) * COST_PER_MILLI_SECOND;
    if (check)
    {
      guessWord = Guess(bestPick);
      money -= COST_OF_GUESS;
    }
  }

  return money;
}

bool checkIfBestPickIsValid(string word, string guess)
{
  for (int i = 0; i < word.size(); i++)
    if (word[i] != guess[i] && guess[i] != '_')
      return false;
  return true;
}

int getValue(string word, unordered_map<char, int> freq)
{
  int value = 0;
  for (char ch : word)
    value += freq[ch];
  return value;
}

unordered_map<char, int> getFrequencyMap(vector<string> &words)
{
  unordered_map<char, int> freq;
  for (string word : words)
    for (char ch : word)
      freq[ch]++;

  return freq;
}