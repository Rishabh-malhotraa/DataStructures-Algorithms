#include <bits/stdc++.h>
using namespace std;

/*
) -> (

operation done  = 1


open backet  = 1

ops = 1

        |
)  (()) ( (  (
(  (()) ( )  )

 X X X
()()()

|          X   X
(  ()()()  )  ()
of we have n open brackets

open_backets_left -> the number of opening brackets in out buffer
then we would require open_backets_left/2 operations to make them balence

- you do linear scan
- you find out a cofiguration when you get into an invalid state

change on closing bracket to open

keep a count of open brackets

and we would have to peform n/2 operation

(



)((()))(((


we will maintain a counter of number of open paranthesis



          |
  )(())(((

  ((()) ( ( (
        X   X

  ((()) ) ( )
  ((()))

  1. (((( -> n/2

  2. ')' -

  if we have 4 opening brackets extra -> then we would require 2 swap to make 2 '(' as ')'

  operation = 1
  open_bracket = 4

  test case 3:
  )((((
  (((((  -> 5 open brackets

  if at the end we get open brackets as odd then we cannot get to a valid state
  return -1

Time complexity -> O(N)
Space COmplexity- > O(1)

*/

int minimumOperation(string &brackets)
{
  int open_brackets = 0, n = brackets.size();

  if (n % 2 == 1)
    return -1;

  int operations = 0;
  for (int i = 0; i < n; i++)
  {
    char ch = brackets[i];

    if (ch == ')')
    {
      if (open_brackets == 0)
      {
        open_brackets++;
        operations++;
      }
      else
      {
        open_brackets--;
      }
    }
    else
    {
      open_brackets++;
    }
  }

  operations += (open_brackets / 2);
  return operations
}

int main()
{
  // you can write to stdout for debugging purposes, e.g.
  std::cout << "This is a debug message" << std::endl;

  return 0;
}

/*

Question 2 : Force a win

51


0-10

Me         Me
3 -> 12 -> 22 -> 32 -> 42 -> 51

make sure the other person is never in range of 1-10 in his turn

51-> 40 -> 1 -> 51

if I get to 41 in my turn I win
  41-51

if i speak i 40

=>   29


= > 18

->  7


Question is 7 is a critical

6 -> 7 -> 5
     13  18


7 -> 10 ->

*/
