#include <iostream>
#include <vector>

// hey

// can you join this

// https://meet.google.com/daf-pkid-jqx

// my video does not work on pramp

//

// I am here
// Ok let me try

/*

input:  inputMatrix  = [ [1,    2,   3,  4,    5],
                         [6,    7,   8,  9,   10],
                         [11,  12,  13,  14,  15],
                         [16,  17,  18,  19,  20] ]


  Method 1:  have 4 Loops


  Method 2 : Simulation


  dir  -> go right  {0, 1}
  we reach a dead end we change the direction vector

  {1, 0}

    (visted)
   [1,    2,   3,  4,    5],
    --------------------->   |
   |                         |
   |                         |
                             |
                             v

         end_j
   1 2 3 4
   8 9 4 6      end
   3 4 6 1     start
       X

  */

using namespace std;

int start_i = 0, start_j = 0;
int end_i, end_j;

bool isValid(int i, int j)
{
  return (i >= start_i && i < end_i && j >= start_j && j < end_j);
}

void editBoundries(int idx)
{
  if (idx == 0)
    start_i++;
  else if (idx == 1)
    end_j--;
  else if (idx == 2)
    end_i--;
  else if (idx == 3)
    start_j++;
}

vector<int> spiralCopy(vector<vector<int>> &inputMatrix)
{

  vector<int> result;
  int m = inputMatrix.size(), n = inputMatrix[0].size();
  end_i = m, end_j = n;

  //    right    down    left   up
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int i = 0, j = 0;
  int idx = 0;

  // while (result.size() < m * n) the following also works
  while (start_i < end_i && start_j < end_j)
  {
    result.push_back(inputMatrix[i][j]);

    if (isValid(i + dir[idx][0], j + dir[idx][1]) == false)
    {
      editBoundries(idx);
      idx = (idx + 1) % 4;
    }

    i += dir[idx][0];
    j += dir[idx][1];
  }
  return result;
  // your code goes here
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  auto result = spiralCopy(grid);

  for (int el : result)
    cout << el << " ";

  return 0;
}