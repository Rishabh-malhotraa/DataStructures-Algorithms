/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/***********************************************************************

  Fair Log Truncation Problem
  ---------------------------

  You are given a list of log messages, each associated with some
  "source" which emitted them.

  Your goal is to truncate the list down to max_size. That is,
  we want to return a subset of the original list.

  However, we want to perform the truncation in a "fair" manner.
  For the sake of this problem, "fair" means the following:

  * There is a threshold X.

  * For each source:

    ** if the source has emitted more than X messages, truncate
       the log messages for that source to X messages;

    ** if the source has emitted X messages or less,
       do not truncate the log messages for that source.

  The goal of this problem is twofold:

  * Find the maximum value of X which causes the total number
    of messages retained across all sources to be less or
    equal max_size.

  * Perform the truncation, returning the truncated list.


 max COunt = 2

 list ['A','B','A']

 // maxFrequecyofSource = 2

 max_size=1 -> X=0, result=[]

 max_size=2 -> X=1, result=[ A, B]
               result.size() == 2

 max_size=3 -> X=2, result=[ A, B, A]
               result.size() == 3



// Method 1: Use hashmap
the size of list can be more than maxThreshold
list = [A,B,C]  maxThreshold  = 3
X = 1

[A,B,A]  maxThreshiold = 3
X = 2


[A,A,A] maxTHreshold = 3
X= 3


Method 1:

hash_map -> A=1
            B=1

 the problem occurs when our list size > maxThershold

          |
 [A,B,A,C,A]  maxSize = 4
 <------->
 SIZE OF LIST = 4

 A -> 2
 b -> 1
 C -> 1

 RETURN []

  A  B  C




[A,A,A,A,A]  maxSize = 4


 WE need to find the maximum threshold

            X
 1: -> 2 -> 3 -> 4


 we can have bound of max Threshold

 l = 0   r = n  (n=5)


suppose if  l = 3  (if we know this maximum threshold is valid, then the max threshold for )




***********************************************************************/

#include <string>
#include <vector>

struct LogMessage
{
  std::string source_name;
  std::string content;
};

using LogMessages = std::vector<LogMessage>;

/*
a - 2
b - 1  maxthreshold = 3
c - 1

if we have maxthreshold = 3

frequenc=ies of every element can be atmost 3

once you apply the truncation logic


 frequencies = [3, 1, 1]
 total_size = 0
 for (auto x : frequencies) {
   total_size += min(x, X);
 }
 total_size <= max_size


*/

bool isPossible(unordered_map<string, int> &freq, int threshold, int max_size)
{
  int curr_size = 0;

  for (auto &[key, count] : freq)
  {
    curr_size = min(threshold, count);
  }

  return curr_size <= max_size;
}

LogMessages TruncateLogMessages(LogMessages messages, int max_size)
{
  int l = 0, r = max_size;

  unordered_map<string, int> freq;

  for (auto [source_name, content] : messages)
    freq[source_name]++;

  while (l < r)
  {
    int mid = unsigned(l + r + 1) / 2;
    if (isPossible(freq, mid, max_size))
      l = mid;
    else
      r = mid - 1;
  }

  // lru
  unordered_map<string, deque<LogMessage>> list; // SC: O(N) -> where n is the size of the
  for (auto [source_name, content] : messages)
    list[source_name].push_back({source_name, content});

  LogMessages result;
  for (auto &[name, messages] : list)
  {
    while (messages.size() > l)
      messages.pop_front();
    result.insert(result.end(), messages.begin(), messages.end());
  }

  return result;
}
/*
time comlexity - > mlog(N)
m - size of frequency list
n -> size of list

*/