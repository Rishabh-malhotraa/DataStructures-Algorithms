/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthLongestPath(string input)
  {
    vector<pair<int, string>> directories;

    stringstream ss(input);
    string token;
    while (getline(ss, token, '\n'))
    {
      int i = 0;
      for (i = 0; i < token.size() && token[i] == '\t'; i++)
        ;
      directories.push_back({i, token.substr(i)});
    }

    string currentFile = "";
    int largestFile = 0;
    stack<pair<int, string>> s;

    for (auto &[level, fileName] : directories)
    {
      while (!s.empty() && s.top().first >= level)
      {
        // abcd + zzz  => 7
        int eraseLen = s.top().second.size();
        int n = currentFile.size() - eraseLen;
        s.pop();
        currentFile = currentFile.substr(0, n);
      }

      currentFile.append(fileName);
      s.push({level, fileName});
      if (fileName.find('.') != string::npos)
        largestFile = max(largestFile, (int)currentFile.size() + level);
    }

    return largestFile;
  }
};

/*

represent the files


vector<string> files  ->

  '\n'


dir
1 subdir1\n
1 subdir2\n
2 file.ext

"dir\n\tsubdir1\n\t\tfile1.ext\n
 \t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"

  v.erase(vec.begin()+ pos, vec.end())''
  0 dir
  1 subdir1
  2 file1.ext
  2 subdir1
  1 subdir2
  2 subsubdir2
  3 file2


dir
 subdr1
 subdir2


2 file.ext
1 subdir2
0 dir

dir
   (\t)subdir1
        \n\t  --> {file.ext}
        \n\t  -->


 dir
   -> subdir
   -> subdir
*/