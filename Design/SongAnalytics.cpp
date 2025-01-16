/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// It was like design a Music Player analytics sort of service(in memory), that prints most played song.


class Compare {
  bool operator()(const pair<string, int >a, const pair<string, int>b) {
    return a.second > b.second;
  }
};


/*

Usera ->

userID -> favorite

userID ->

*/

struct Song {
  string song;
  int playCount;
};

class Analytics {
private:
  unordered_map<string, list<string>> usersHistory; // user -> songId
  unordered_map<string, unordered_set<string>> usersFavorites;

  // Tracks 
  unordered_map<string, Song> songs;

  // Tracks which users played which songs: songId -> set of userIds
  unordered_map<string, unordered_set<string>> songUserPlays;


public:
  void playSong(string songId, string userId) {
    unordered_set<string>& userList = songUserPlays[songId];

    if (userList.find(songId) == userList.end()) {
      userList.insert(songId);
      songs[songId].playCount++;
    }

    usersHistory[userId].push_front(songId);
  }

  void addSong(string songId, string title) {
    songs.insert({ songId, {title, 0} });
  }

  void printAnalytics() {
    vector<Song> songList;
    for (auto [songId, song] : songs)
      songList.push_back(song);

    sort(songList.begin(), songList.end(), [](Song a, Song b) {
      return a.playCount > a.playCount;
      });

    for (int i = 0; i < 10; i++) {
      cout << songList[i].song << " " << songList[i].playCount << endl;
    }
  }

  void starSong(string userId, string songId) {
    usersFavorites[userId].insert({ songId });
  }


  void unstarSong(string userId, string songId) {
    usersFavorites[userId].erase(songId);
  }


  vector<string> getLastNFavoriteSongs(string userId, int n) {
    list<string> songList = usersHistory[userId];
    unordered_set<string> favorites = usersFavorites[userId];
    vector<string> lastNFavoriteSongs;
    int idx = 0;
    for (string songId : songList) {
      if (idx < n)
        break;

      if (favorites.find(songId) != favorites.end())
        lastNFavoriteSongs.push_back(songId);
      idx++;
    }
    return lastNFavoriteSongs;
  }
};




// I was able to code.Then they asked a follow up to add a feature to star / unstar song(s) for a user
//  and get last N favourite songs played(something like that).I wasn't able to fully write the working code for it as time was up.