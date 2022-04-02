/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * **LEADER SHIP QUESTION**
 * Tell a time when you had to make a decision based on a strict deadline
 * 2nd Question -- I don't know this question lol. RIP - This questions could be the reason
 * Dive Deep - Do it differently :- Good -- Tell about conflict Resolutions
 * Learn from the Project - Prioritisation
 * Tell about time you did something difficult. Or different

I would rate myself a 5/10 on this interview

Full Marks on Data Structure -- like what else can I do.

getPort() -> 0
getPort() -> 1
getPort() -> 2
returnPort(1) -> void
getPort() -> 1
getPort() -> 3

*/
class PortAllocation
{
private:
  priority_queue<int, vector<int>, greater<int>> availablePorts;
  set<int> allocatedPorts;
  unsigned int nextPort = 0;

public:
  int getPort()
  {
    int port;
    if (availablePorts.empty() == true && nextPort == INT_MAX)
      throw "Out of Bounds";

    if (availablePorts.empty() == true)
    {
      allocatedPorts.insert(nextPort);
      port = nextPort++;
    }
    else
    {
      port = availablePorts.top();
      availablePorts.pop();
      allocatedPorts.insert(port);
    }
    return port;
  }
  void returnPort(int port)
  {
    if (port < 0)
      throw invalid_argument("PORT should not be less that 0");

    if (allocatedPorts.find(port) == allocatedPorts.end())
      throw "PORT has not been allocation, we cannot free an unallocated port.";

    allocatedPorts.erase(allocatedPorts.find(port));
    availablePorts.push(port);
  }
};
