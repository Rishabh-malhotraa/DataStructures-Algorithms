/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class Directory
{
public:
  unordered_map<string, string> files;
  unordered_map<string, Directory *> subdir;
};

class FileSystem
{
private:
  Directory *root;
  char delimeter = '/';

  vector<string> getDirectories(string &path)
  {
    vector<string> directories;
    stringstream ss(path);
    string token;
    while (getline(ss, token, delimeter))
      directories.push_back(token);
    return directories;
  }

  Directory *searchOrCreate(vector<string> &dir)
  {
    Directory *node = root;
    int idx = 1;
    while (idx < dir.size() - 1)
    {
      string dirName = dir[idx];
      if (node->subdir.find(dirName) == node->subdir.end())
        node->subdir[dirName] = new Directory();

      node = node->subdir[dirName];
      idx++;
    }
    return node;
  }

public:
  // 1. Design a trie based data structure?

  FileSystem()
  {
    root = new Directory();
  }

  vector<string> ls(string path)
  {
    vector<string> dir = getDirectories(path);
    Directory *node = searchOrCreate(dir);
    string last = dir.back();

    if (node->files.find(last) != node->files.end())
      return {last};
    else
    {
      if (last != "")
        node = node->subdir[last];
      vector<string> list;
      for (auto [fileName, _] : node->files)
        list.push_back(fileName);

      for (auto [subDirName, _] : node->subdir)
        list.push_back(subDirName);

      sort(list.begin(), list.end());
      return list;
    }
  }

  void mkdir(string path)
  {
    vector<string> dir = getDirectories(path);
    Directory *node = searchOrCreate(dir);
    string last = dir.back();

    node->subdir[last] = new Directory();
  }

  void addContentToFile(string filePath, string content)
  {
    vector<string> dir = getDirectories(filePath);
    Directory *node = searchOrCreate(dir);
    string last = dir.back();

    node->files[last].append(content);
  }
  string readContentFromFile(string filePath)
  {
    vector<string> dir = getDirectories(filePath);
    Directory *node = searchOrCreate(dir);
    string last = dir.back();

    return node->files[last];
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */