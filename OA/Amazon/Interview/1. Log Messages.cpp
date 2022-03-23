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
* 9/10 Interview [A]

* **LEADERSHIP QUESTION**
1. Tell me a time in which you had difference of Opinion with someone
    - Tailwind CSS - Disagree
    - How to Handle Conflict
2. How you Exceeded Expectation
    - Joplin Tables (Good)
3. Tell me a time you had diffrence of achieve certain things
    - UI/UX (Not Very Good Answer)

Asked Good Questions to the Interview
  - Advice
  - How Covid Impacted Culture at Amazon

========================================================
Parse log file

You have an application which sends messages, and it has a log file which has the following format:

timestamparbitrary text

The timestamp is in ISO 8601 format: "YYYY-MM-DDThh:mm:ssZ"

The following is an example of the log:

2018-10-23T09:35:29Z sent message
2018-10-23T09:44:01Z transmit error
2018-10-23T09:49:29Z sent message
2018-10-23T10:01:49Z sent message
2018-10-23T10:05:29Z transmit error
2018-10-23T10:06:05Z transmit error
2018-10-23T10:07:17Z transmit error
2018-10-23T11:23:24Z sent message
2018-10-23T11:52:28Z sent message
2018-10-23T12:01:13Z transmit error

Pretend that you are going to write a library which can parse log files in this format.
After you write it, you will hand the library over to another team,
who will maintain and possibly extend its features.
So the maintainability of your code will be important.

Could you write some code (in language of your choice) which:

(1) Filters the log file to find only the lines which contain "transmit error"

(2) Counts how many times those errors occurred

(3) Saves those lines which contain errors into a different file -- Create a Historgram

========================================================

*/

class ParseLogs
{
private:
  vector<string> logs;
  vector<string> errorLogs;

  bool isErrorLog(string &log)
  {
    string msg = log.substr(log.find(' '));
    return msg == "transmit error";
  }

  int getHour(string log)
  {
    // 2018-10-23T09:44:01Z transmit error
    int idx1 = log.find('T'), idx2 = log.find('Z');
    string time = log.substr(idx1, idx2 - idx1);
    int hour = stoi(time.substr(0, time.find(':')));

    return hour;
  }

public:
  vector<string> parseError()
  {
    for (string log : logs)
      if (isErrorLog(log) == true)
        errorLogs.push_back(log);

    return errorLogs;
  }

  int numberOfErrorLogs()
  {
    return errorLogs.size();
  }

  vector<vector<string>> createHistogram()
  {
    vector<vector<string>> histogram(24, vector<string>{});

    for (string log : errorLogs)
    {
      int hour = getHour(log);
      histogram[hour].push_back(log);
    }

    return histogram;
  }
};
