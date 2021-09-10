/*
function isValid(stale, latest, otjson)
{
  // this is the part you will write!
}

isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations.',
    '[{"op": "skip", "count": 40}, {"op": "delete", "count": 47}]'); // true

isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations.',
    '[{"op": "skip", "count": 45}, {"op": "delete", "count": 47}]'); // false, delete past end

isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations.',
    '[{"op": "skip", "count": 40}, {"op": "delete", "count": 47}, {"op": "skip", "count": 2}]'); // false, skip past end

isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'We use operational transformations to keep everyone in a multiplayer repl in sync.',
    '[{"op": "delete", "count": 7}, {"op": "insert", "chars": "We"}, {"op": "skip", "count": 4}, {"op": "delete", "count": 1}]'); // true

isValid(
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    'Repl.it uses operational transformations to keep everyone in a multiplayer repl in sync.',
    '[]'); // true

*/

/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

class OperationsType
{
public:
  string ot;
  int count;
  string chars;
};

class OperationalTransformation
{
private:
  int cursor_position;

  int _skip(string text, int count)
  {
    if (count + cursor_position < text.size())
      return count + cursor_position;
    else
      return text.size();
  }

  string _insert(string text, string insertText)
  {
    cursor_position = cursor_position + insertText.size();
    return text.substr(0, cursor_position) + insertText + text.substr(cursor_position);
  }

  string _delete(string text, int count)
  {
    count = min(cursor_position + count, (int)text.size());
    return text.substr(0, cursor_position) + text.substr(count);
  }

public:
  OperationalTransformation(int intital_position = 0)
  {
    cursor_position = intital_position;
  }

  bool isValid(string stale, string latest, vector<OperationsType> &ot)
  {
    for (OperationsType Operation : ot)
    {
      if (Operation.ot == "skip")
        cursor_position = _skip(stale, Operation.count);

      else if (Operation.ot == "insert")
        stale = _insert(stale, Operation.chars);

      else if (Operation.ot == "delete")
        stale = _delete(stale, Operation.count);
    }

    return stale == latest;
  }
};
