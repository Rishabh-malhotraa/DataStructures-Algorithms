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
A state consists of N cities numbered from 0 to N-1. All the road in the state are bidirectional.
Each city is connected to another city by one direct road only. A magician travels  to these cities to perform shows.
He knows a magic spell that can completely eliminate the distance between any two directly connected cities.
But he must be very carefuil because the magic spell can be performed only K number of times 

Write an algorithm to find the length of the shortest route between two given cities after performing magic spell K number of times.
Output -1 if no path exist.
*/