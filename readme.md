<p align="center">"Think twice, code once"</p>

# Overview

I use this repository to document of Leetcode and codeforces Problem I solve everyday.

The **folders structure** is following:

- [`scripts`](./scripts): small scripts for automatizing some repetitive tasks.
- [`solutions`](./solutions): code of accepted problems, categorized by online judges.
  - [`README.md`](./solutions/README.md): solutions index by themes, containing difficulty, name, description and hint of the problem.
    -->

# Notebook index

## 🧱 data structures

- [Arrays](./Arrays)
- [Strings](./Strings)
- [Stacks & Queues](./Stacks%20%26%20Queues)
- [Hash Map](./notebook/data-structures/ufds.cpp)
- [Trees](./Trees)
- [Graphs](./Graphs)
- [Tries](./Tries)
  <!-- - Wavelet tree https://github.com/andrefakhoury/competitive-programming/blob/master/lib/DataStructures/WaveletTree.hpp -->

## Algorithms

- [Binary Search](./Binary%20Search)
- [DFS & BFS](./DFS%20%26%20BFS)
- [Sorting](./Sorting)
- [Backtracking](./Backtracking)

### 🔞 dynamic programming

- [Decision Making](./Dynamic%20Programming/Decision%20Making)
  - Knapsack and its Variations
  - Buy and sell Stock I - V
- [DP on Strings](./Dynamic%20Programming/DP%20on%20Strings)
  - Longest common subsequence and its variation
  - Pattern Matching
- [DP on Grid](./Dynamic%20Programming/DP%20on%20Grid)
  - Ways to reach end point in a grid
  - Cherry Pickup + Dungeoun Game
- [DP on Row](./Dynamic%20Programming/DP%20on%20Row)
  - Jump Game I - V
  - Climbing Stairs
  - Fibonacci Type Questions
- [Longest Increasing Subsequence](./Dynamic%20Programming/Longest%20Increasing%20Subsequence)
  - FIND LIS
  - Russion Doll Variations -> LIS on two variables
- [Merge Intervals](./Dynamic%20Programming/Merge%20Intervals)
  - Burst Ballons
  - Remove Boxes
- [Optimal Game Strategy](./Dynamic%20Programming/Optimal%20Game%20Strategy)
  - Stone Game I-VII
- [Others](./Dynamic%20Programming/../Dynamic%20Programming/Others)
  - Word Break
  - Knight Dialer
  - Largest Rectangle

## 🌍 graphs

- [data structures representation](./notebook/graphs/ds-representation.md)
- **traversal**
  - [depth-first search (DFS)](./notebook/graphs/dfs.cpp)
  - [breadth-first search (BFS)](./notebook/graphs/bfs.cpp)
  - [flood fill](./notebook/graphs/flood-fill.cpp)
  - [edge classification](./notebook/graphs/edge-classification.cpp)
  - [bridges and articulations points](./notebook/graphs/bridges-and-articulations.cpp)
  - [strongly connected components (SCC)](./notebook/graphs/scc.cpp)
  - **topological sorting**
    - [kahn](./notebook/graphs/topo-sort-kahn.cpp)
    - [naive](./notebook/graphs/topo-sort.cpp)
- **minimum spanning tree (MST)**
  - [kruskal](./notebook/graphs/mst-kruskal.cpp)
  - **variants**
    - [minimax path](./notebook/graphs/mst-minimax-path.cpp)
    <!--TODO - [2nd best MST](./notebook/graphs/mst-2nd-best.cpp) -->
- **network flow**
  - [max flow w/ edmonds karp](./notebook/graphs/edmonds-karp.cpp)
  - [min cost max flow](./notebook/graphs/mcmf.cpp)
- **shortest path**
  - **single-source**
    - [bellman ford](./notebook/graphs/bellman-ford.cpp)
    - [dijkstra](./notebook/graphs/dijkstra.cpp)
    <!-- - **all-pairs** -->
- **specials**
  - [**bipartite graph**](./notebook/graphs/bipartite.md)
    - [bipartite checking](./notebook/graphs/bipartite-checking.cpp)
    - [maximum cardinality bipartite matching](./notebook/graphs/mcbm.cpp)
  - [**directed acyclic graph**](./notebook/graphs/dag.md)
  - [**tree**](./notebook/graphs/tree.md)
    - [heavy-light decomposition (HLD)](./notebook/graphs/hld.cpp)
    - **lowest common ancestor (LCA)**
      - [binary lifting](./notebook/graphs/lca-binary-lifting.cpp)
      - [eulerian tour](./notebook/graphs/lca-eulerian-tour.cpp)

## ✏️ math

- **number theory**
  - [fast exponentiation](./notebook/math/fast-power.cpp)
  - **prime numbers**
    - [prime checking](./notebook/math/prime-checking.cpp)
    - [sieve of eratosthenes](./notebook/math/sieve.cpp)
    - [modified sieve](./notebook/math/modified-sieve.cpp)
    - [optimized prime checking](./notebook/math/optimized-prime-checking.cpp)
    - [prime factors of n](./notebook/math/prime-factors.cpp)
    - [prime factors of n!](./notebook/math/factorial-prime-factors.cpp)
    - [number of divisors of n](./notebook/math/num-div.cpp)
    - [sum of divisors of n](./notebook/math/sum-div.cpp)
- **matrix exponentiation**
  - [linear recurrences](./notebook/math/linear-recurrence.cpp) - [utility in graph](./notebook/math/linear-recurrence-graph.cpp) - [utility in counting](./notebook/math/linear-recurrence-counting.cpp)
    <!-- - [**game theory**](./notebook/math/game-theory.md) -->
       <!-- - [minimax](./notebook/math/minimax.md) -->
       <!-- - [nim](./notebook/math/nim.md) -->
       <!-- - [grundy numbers]() -->
       <!-- - [sprague-grundy theorem]() -->

<!-- ## strings -->

## 💭 miscellaneous

- [binary search](./notebook/miscellaneous/binary-search.md)
- [bitmasks](./notebook/miscellaneous/bitmasks.cpp)
- [two pointers](./notebook/miscellaneous/two-pointers.md)

# References

- [_SDE Sheet by Striver_](https://docs.google.com/document/d/1SM92efk8oDl8nyVw8NHPnbGexTS9W-1gmTEYfEurLWQ/preview?pru=AAABeuuop9I*PUtrb2ew2hKp83BXQGBofg)
- [_DSA Sheet by Fraz_](https://docs.google.com/spreadsheets/d/1-wKcV99KtO91dXdPkwmXGTdtyxAfk1mbPXQg81R9sFE/edit#gid=0)
- [_FAANG Listt 2.0 by PepCoding_](https://www.pepcoding.com/faangList2.0)
