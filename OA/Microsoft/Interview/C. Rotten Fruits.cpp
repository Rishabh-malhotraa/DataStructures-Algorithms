#include <bits/stdc++.h>
using namespace std;

/*

  0            X
0 X 0   ->  X  X  X
  0            X

graph data strucutre would be good



assumption here is neighbours exist in top bottom right left

0 0 0
0 X 0
0 0 0

  0
 000
00000


if we don't want to represent this as matrix graph

we can just use adjacent list

X -> {}

  ---
 | X |
 ----

do some sort of level order traversal



Node -> neighbours


Node


    X -> {1, 2, 3, 4, 5}

    5-> {X, 1, 2}


*/

class Node
{
public:
  int position;
  bool isRotten;
};

/**
 * Find minimum hours to rot all possible fruits.
 * @param { map<Node, list<Node>> } - Adjacency list graph of all the neighbours of a given fruit
 * @param {Node} rottenFruit - The rotten fruit node.
 */
int rottenFruits(map<Node, list<Node>> graph, Node rottenFruit)
{

  queue<Node> q;

  q.push(rottenFruit);

  map<Node, bool> visited;

  visited.insert({rottenFruit, true});

  int hours = 0;

  while (q.empty() == false)
  {
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
      Node currNode = q.front();
      q.pop();

      for (Node neighbour : graph[currNode])
        if (visited[neighbour] == false)
        {
          visited[neighbour] = true;
          neighbour.isRotten = true;
          q.push(neighbour);
        }
    }
    hours++;
  }

  return hours;
}

/*
Merge Sets

lb is the first element >= than the given element
we sort this in nLogn

                X
1   2   3  5  5 7 8  -- arr[0]


             X
4   5   6  7


X
7   8   9

->{7 }


TIme compleixty -> N * m_i  =>

m_i => minimum length of set

Optimisations


1. early exit condition if we find intersection to be NULL
2. if for set = a , set b  b.front() > a.back()

3.


Observations

O (N+M)*K -> O(N^2)


size of set A = N
size of set B = M

numebr of sets we have N

set a ->


              X
set -> 1 2 3 4 5

       X
       6 7 8
->

*/