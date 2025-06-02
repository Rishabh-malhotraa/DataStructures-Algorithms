/*
1. Closest Numbers

Given an array of distinct integers, determine the minimum absolute difference between any two elements.Print all pairs of elements with that difference, ensuring the smaller number appears first in each pair, and the pairs are sorted in ascending order.

Example

numbers = [6, 2, 4, 10]

The minimum absolute difference is 2 and the pairs with that difference are :

2 4
4 6


⸻

Function Description

Complete the function closestNumbers in the editor.

void closestNumbers(vector<int> numbers);

Parameters
•	int numbers[n]: an array of integers

⸻

Returns
•	None

⸻

Prints
•	Distinct element pairs that share the minimum absolute difference, displayed in ascending order with each pair separated by one space on a single line.

⸻

Constraints
•	2 <  n > ^ 5
• - 10 ^ 9 <  numbers < 10 ^ 9

*/

#include <bits/stdc++.h>
using namespace std;


void closestNumbers(vector<int> numbers) {
  sort(numbers.begin(), numbers.end());
  int n = numbers.size();
  int min_diff = INT_MAX;

  for (int i = 0; i < n - 1; ++i) {
    int diff = numbers[i + 1] - numbers[i];
    min_diff = min(min_diff, diff);
  }

  for (int i = 0; i < n - 1; ++i) {
    if (numbers[i + 1] - numbers[i] == min_diff) {
      cout << numbers[i] << " " << numbers[i + 1] << endl;
    }
  }
}