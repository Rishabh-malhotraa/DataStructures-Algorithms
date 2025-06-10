#include <bits/stdc++.h>
using namespace std;


class FileTailReader {
public:
  FileTailReader(string fileDescriptor, int bufferSize = 4096) {
    fileName = fileDescriptor, CHUNK_SIZE = bufferSize;

    file.open(fileName, ios::in);

    stringstream ss;
    ss << file.rdbuf();
    cout << ss.str() << endl;
    file.seekg(0, std::ios::end);

  }

  ~FileTailReader() {
    file.close();
  }

  std::string tail(int numberOfLines = 10) {
    list<string> collected;
    int lineCount = 0;
    string buffer = "";
    int ongoingBuffer = 0;

    while (currOffset > 0 && lineCount <= numberOfLines) {
      int idx = buffer.rfind('\n');

      if (idx == string::npos) {
        int DIR = -1;
        int bufferSize = (currOffset < CHUNK_SIZE ? currOffset : CHUNK_SIZE);
        ongoingBuffer += bufferSize;
        currOffset -= bufferSize;

        string tempBuffer(bufferSize, '\0');
        file.seekg(ongoingBuffer * DIR, ios::end);
        file.read(tempBuffer.data(), bufferSize);
        buffer = tempBuffer + buffer;
      }
      else {
        collected.push_front(buffer.substr(idx));
        lineCount++;
        buffer.erase(buffer.begin() + idx, buffer.end());
      }
    }

    string content;
    for (string s : collected) {
      content = content + s;
    }

    return content;
  }
private:
  string fileName;
  ifstream file;
  int CHUNK_SIZE;
  int currOffset;
};


int main() {
  int n = 10;
  // cout << "How many lines do you want to tail?" << endl;
  // cin >> n;
  FileTailReader f("log.txt", 20);

  cout << f.tail(n) << endl;;
}


