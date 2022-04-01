/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
  unordered_map<int, unordered_set<int>> cache;
  deque<pair<int, int>> tweets;
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    tweets.push_front({userId, tweetId});
  }

  vector<int> getNewsFeed(int userId)
  {
    int n = tweets.size();
    vector<int> result;
    for (int i = 0; i < n && result.size() < 10; i++)
    {
      auto [id, tweetId] = tweets[i];
      if (id == userId || cache[userId].find(id) != cache[userId].end())
        result.push_back(tweetId);
    }
    return result;
  }

  void follow(int followerId, int followeeId)
  {
    cache[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    cache[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */