/*

PART I

We are building a cloud-based music player, like Spotify.
Let's start with the following functionality:

* `addSong (songTitle [string])`
   - A song is given an incremental integer ID when it's added, starting with 1


* `playSong (songId [integer], userId [integer])`
   - Assume any user ID is valid, and that the given song ID will have been added


* `printAnalyticsSummary ()`
   - This is used for a report, created once per day for our company's Analytics department.
   - The summary should be sorted (descending) by the number of unique users who have played each song.
   - The summary should include the song titles, and the number of unique users, but the formatting does not matter.

For our MVP, consider performance as we will eventually support millions of songs and users.
However, let's not worry about thread safety or persistence for now - store data in memory.

Expected output:
* "Hello, Goodbye" has been played by 4 unique users
* "Stairway to Heaven" has been played by 3 unique users
* "Bohemian Rhapsody" has been played by 2 unique users
* "Satisfaction" has been played by 1 unique user
* "Pinball Wizard" has been played by 0 unique users



PART II

We now want to allow users to see their most recently played songs.
Let's implement the following function:
* `lastThreePlayedSongTitles (userId [integer])`
   - Returns the titles of the last three unique played songs for the given user (ordered, most recent first)
Let's prioritize solving the problem for the last three played songs for now.
We can tackle extensibility at a later stage.
After running the new function with the plays from the previous example,
the summary should output as follows for user ID 1 (in order):
Hello, Goodbye
Stairway to Heaven
Bohemian Rhapsody
*/

/*

PART III
We now want to revisit the first question, and printing the analytics summary.
Sorting the songs by the number of unique users who have played each song is taking too long.
We also find that the Analytics department is only interested in the top few songs - a number that changes depending on their task.
We now want to modify the `printAnalyticsSummary` function to take a parameter, `k`.
The function should print the top `k` songs by the number of unique users who have played each song.
We can modify any of the existing functions, but all of them must perform better than `O(N log N)`.

*/

/*
top K songs -> quick Slecet -> O(2*N)

heap -> O

## Approach

1. I want to have some sort of container that would map the songId -> songTitle

2. Songs[songID] -> [user who played the songs]
   map<int, unordered_set<int>> songs : this maps every songId with every unique user who plays this song

3.

*/

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
// #include <bits/stdc++.h>x

// #include <bit/stdc++.h>

using namespace  std;

/*
TC:

O(N+M)
where N is the nu
*/

class Library {
private:
  // this maps every songId -> list of users who played this song
  unordered_map<int, unordered_set<int>> songs;
  vector<string> songNames;
  unordered_map<int, deque<int>> userLastPlayedSongs;
public:
  Library() {
    songNames.push_back("");
  }

  void addSong(string songName) {
    songNames.push_back(songName);
    int idx = songNames.size() - 1;
    songs[idx] = unordered_set<int>{};
  }

  void playSong(int songId, int userId) {
    songs[songId].insert(userId);

    if (userLastPlayedSongs.find(userId) == userLastPlayedSongs.end()) {
      userLastPlayedSongs[userId] = deque<int>{};
    }

    deque<int>& lastSongsPlayed = userLastPlayedSongs[userId];
    if (lastSongsPlayed.size() == 3) {
      lastSongsPlayed.pop_front();
    }

    lastSongsPlayed.push_back(songId);
  }



  /*

      LFU cache  -> N element

      list [ 0, 1, 2, ,4]
             |
            |
           |
    */
  void printAnalyticsSummary() {
    // this would contain songId, and number of unique plays
    vector<pair<int, int>> analytics;
    for (auto& [songId, users] : songs) {
      analytics.push_back({ songId, users.size() });
    }

    // O(NlogN) where N is the nuber of unique songs
    sort(analytics.begin(), analytics.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
      });

    for (auto [songId, numberOfPlays] : analytics) {
      cout << " " << songNames[songId] << " " << numberOfPlays << endl;
    }
  }

  // we have a deueue with size 3
  void lastThreePlayedSongTitles(int userId) {
    deque<int> lastSongsPlayed = userLastPlayedSongs[userId];
    for (int songId : lastSongsPlayed) {
      cout << songNames[songId] << endl;
    }
  }
};

int main() {
  Library library;

  library.addSong("Hello, Goodbye");
  library.addSong("Bohemian Rhapsody");
  library.addSong("Stairway to Heaven");
  library.addSong("Satisfaction");
  library.addSong("Pinball Wizard");

  library.playSong(1, 9);
  library.playSong(2, 14);
  library.playSong(1, 2);
  library.playSong(1, 1);
  library.playSong(2, 1);
  library.playSong(3, 17);
  library.playSong(2, 1);
  library.playSong(3, 5);
  library.playSong(2, 1);
  library.playSong(2, 1);
  library.playSong(1, 7);
  library.playSong(4, 1);
  library.playSong(2, 1);
  library.playSong(1, 1);
  library.playSong(1, 1);
  library.playSong(3, 1);
  library.playSong(1, 1);

  library.printAnalyticsSummary();
  library.lastThreePlayedSongTitles(1);

}



