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
**LEADERSHIP QUESTION**

* 7.5 - 8/10 Interview [B+]

1. Tell me a time in which you achieved more that what was asked of you. [12 minutes]
    - Joplin Tables - [This was a mistake]
2. Example of Dive Deep
    - Good Answer - Conflict Free Replicated Data Types
*/

/*
We are in charge of designing a system to install packages on computer systems. We are required to support the installation
of a package and all of its dependent packages in the right order.
Here is an example of a package structure that we would need to install:

A depends on B, C
B depends on D, E, F
C depends on F
F depends on G

Define what a package looks like and code a solution to this problem.


A -> B
|
| -> C

A, B are packages



There is no circular dependies
  <-
 |   |
 A-> B


Sort the packages in a way so that we have the least dependant to the most dependant


 C --> F  --> G
 ^     ^
 |     |
 A ->  B  --> D
       |
       V
       E

cyclic(A)
  cyclic(B)                                  -- cyclic(C)
    cyclic(F)   cyclic(D)  cyclic(E)
      cyclic(G) --

A - PROCESSING
B - PROCESSING
C - UNVISITED
D - PROCESSED
E - PROCESSED
F - PROCESSED
G - PROCESSED

order -> G F D E B C

  indegress - the number of packages this package depend on




A -> B
| -> C
*/

// < -A->B

// use inheritance to have a function which uses installation here
class Package : private Installation
{
public:
  string packageName;
  vector<Package *> subDependencies;
  Package(string packageName, vector<Package *> subDependencies)
  {
    this->packageName = packageName;
    this->subDependencies = subDependencies;
  }
  void install()
  {
    this->installationOrder(this); // crazy syntax lol
  }
};

enum Status
{
  UNVISITED,
  PROCESSING,
  PROCESSED,
};

class Installation
{
private:
  bool cyclic(Package *pkg, unordered_map<Package *, Status> isInstalled, vector<Package *> &order)
  {
    if (pkg == NULL)
      return false;

    isInstalled[pkg] = PROCESSING;

    for (Package *dependency : pkg->subDependencies)
    {
      if (isInstalled[dependency] == PROCESSING)
        return true;

      if (isInstalled[dependency] != PROCESSED && isInstalled[dependency] == UNVISITED)
      {
        bool isCyclic = cyclic(dependency, isInstalled, order);

        if (isCyclic)
          return isCyclic;
      }
    }
    order.push_back(pkg);
    isInstalled[pkg] = PROCESSED;
    return false;
  }

public:
  // A -> [B,C,D]
  vector<Package *> installationOrder(Package *pkg)
  {
    if (pkg == NULL)
      throw invalid_argument("NULL Package!");

    vector<Package *> order;
    unordered_map<Package *, Status> isInstalled;

    if (cyclic(pkg, isInstalled, order))
      throw logic_error("Circular Dependencies");

    return order; // {}
  }
};

int main()
{
  Package *pkg = new Package("", {});
  pkg->install();
  return 0;
}
