#include <iostream>
using namespace std;

/*

IP4v addresses are 32-bit integers that are represented in the form of 4 octets: “a.b.c.d”. A CIDR block is a collection of IP addresses with the same significant bits and represented as “a.b.c.d/n”. All IP addresses with the same first n significant bits fall into this block.

Example:

192.168.0.0/24
 11000000.10101000.00000000.00000000
|__________________________| = 24 significant bits

An IP router takes packets and forwards them to the correct next hop based on a routing table. Implement a router that has two functions:

AddRoute(string net, int outInterface)
Route(string IP) -> int

Route should effectively find the matching route for the input IP and return the outbound interface.

Example routing table:

192.168.0.0/24   -> 0
192.168.0.0/16   -> 1


192.168.0.0/24   -> 0
10.2.0.0/16      -> 1
10.0.0.0/8       -> 2
10.1.0.0/16      -> 3

unordered_map<string, pair<string, int>>


  [192.168.0] -> {192.168.0.0/24, 0}
  [10.2] -> {1}
  [10] -> {2}
  [10.1.0] -> {3}

  [0-255] -> (255)^4

  192              10
     \            1  \
      168        /     2
        \       0
         0

192.168.0.2 ->


Example input: 192.168.0.0 -> extract :

Route(string IP) -> int

192.168.0.0/24   -> 0

store =
[192.168.0] -> {192.168.0.0/24, 0}


route(192.168.0.1/27)

unordered_map<string, pair<ip, int>>

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  unordered_map<string, Node*> children;
  bool isTerminal;
  int routeValue;
};


class Router {
public:
  Router() {
    this->root = new Node();
  }

  // AddRoute(string net, int outInterface)
  // "192.168.0.0/24"   0
  void AddRoute(string net, int outInterface) {
    int idx = net.find('/');

    int digits = stoi(net.substr(idx + 1));

    string ip = net.substr(0, idx);

    vector<string> address = split(ip, '.');
    Node* node = this->root;

    for (int i = 0; i < (digits / 8); i++) {
      string currAddress = address[i];
      if (!node->children.contains(currAddress)) {
        node->children[currAddress] = new Node();
      }
      node = node->children[currAddress];
    }

    node->isTerminal = true;
    node->routeValue = outInterface;
    return;
  }

  int Route(string ip) {
    vector<string> address = split(ip, '.');
    Node* node = this->root;

    int idx = 0;
    int n = address.size();

    int answer = -1;
    while (node != NULL && idx < n) {
      string a = address[idx];

      if (node->children.contains(a) && node->children[a]->isTerminal == true) {
        answer = node->children[a]->routeValue;
      }
      node = node->children[a];
      idx++;
    }

    return answer;
  }


private:
  Node* root;
  vector<string> split(string str, char delimeter) {
    stringstream ss(str);
    string token = "";
    vector<string> tokens;
    while (getline(ss, token, delimeter)) {
      tokens.push_back(token);
    }
    return tokens;
  }
};



/*
192.168.0.0/24   -> 0
10.2.0.0/16      -> 1
10.0.0.0/8       -> 2
10.1.0.0/16      -> 3
*/

// To execute C++, please define "int main()"
int main() {
  Router r;

  r.AddRoute("192.168.0.0/24", 0);
  r.AddRoute("10.2.0.0/16", 1);
  r.AddRoute("10.0.0.0/8", 2);
  r.AddRoute("10.1.0.0/16", 3);
  r.AddRoute("10.1.0.0/24", 4);
  r.AddRoute("10.1.0.0/32", 5);

  cout << "Route Value : " << r.Route("10.1.0.0") << endl;

  return 0;
}

/*
[0 - 255] ->

    16.0.0.0/4

    011000000

    01100010  011000000  / 11
       8         3

    i will extr
    act the 8 butes  - 19 -> 16->



192


      10.0.0.0/7

      10 take a maks of the first 7 bits ->

      1 1 1 1  = 16

      number & mask

      192 & 8 -> 192
      192 & 7 -> []

    192 -> [01012121]
           [0000000]

    2^8 = 256 [0-255]

    2^7 = 128

    2^6 = 64

    2^7 = 128

    2^7 = 128

    2^7 = 128

  */




  // Your previous Plain Text content is preserved below:

  // This is just a simple shared plaintext pad, with no execution capabilities.

  // When you know what language you'd like to use for your interview,
  // simply choose it from the dots menu on the tab, or add a new language
  // tab using the Languages button on the left.

  // You can also change the default language your pads are created with
  // in your account settings: https://app.coderpad.io/settings

  // Enjoy your interview!

// void AddRoute(string net, int outInterface) {
//   Node* node = this->root;
//   int idx = net.find('/');
//   int digits = stoi(net.substr(idx + 1));
//   string ip = net.substr(0, idx);
//   vector<string> address = split(ip, '.');

//   int i = 0;
//   while (digits > 0) {
//     string currAddress = address[i++];
//     digits = digits < 8 ? digits : 8;
//     int mask = (1 << digits) - 1;
//     string maskedAddress = to_string(stoi(currAddress) & mask);

//     if (!node->children.contains(maskedAddress)) {
//       node->children[maskedAddress] = new Node();
//     }
//     node = node->children[maskedAddress];
//   }

//   node->isTerminal = true;
//   node->routeValue = outInterface;
//   return;
// }