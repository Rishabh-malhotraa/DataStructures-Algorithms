#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findGrantsCap(vector<int> grantsArray, int newBudget)
{
  int n = grantsArray.size();
  sort(grantsArray.rbegin(), grantsArray.rend());
  vector<int> suffix(n + 1, 0);
  suffix[n - 1] = grantsArray[n - 1];
  for (int i = n - 2; i >= 0; i--)
    suffix[i] = suffix[i + 1] + grantsArray[i];

  int idx = n;
  int sum = suffix[0];
  if (sum <= newBudget)
    return 0;

  for (int i = 0; i < n; i++)
  {
    if ((i + 1) * grantsArray[i] + suffix[i + 1] <= newBudget)
    {
      idx = i;
      break;
    }

    if (i == n - 1)
      return 1.0 * newBudget / n;
  }

  return 1.0 * (newBudget - suffix[idx]) / idx;
}

int main()
{
  return 0;
}

// NOT WORKING SOLUTION

pair<int, int> getCap(int idx, vector<int> &arr, int sumSoFar, int newBudget)
{
  int curr_sum = 0;
  for (int i = idx; i < arr.size(); i++)
  {
    curr_sum += arr[i];
  }

  curr_sum = min(newBudget - sumSoFar, curr_sum);

  return {curr_sum, arr.size() - idx};
}

double findGrantsCap(vector<int> arr, int newBudget)
{
  sort(arr.begin(), arr.end());
  /*
  
  sort the array
  - maintain a sum
  - if the sum + arr[i] > newBuget
  - (newBudget - sum)/ (n-i) => new cap
  - suppose our new cap is less that an element in arr[0..i] 
  
  */
  int n = arr.size();
  int sum = 0;
  pair<int, int> cap;
  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    if (sum + arr[i] > newBudget)
    {
      cap = getCap(i, arr, sum, newBudget);
      cout << cap.first << endl;
      idx = i;
      break;
    }
    else
      sum += arr[i];
  }

  int temp_cap = cap.first / cap.second;

  for (int i = 0; i <= idx; i++)
  {
    if (arr[i] > temp_cap)
    {
      cap.first += arr[i];
      cap.second += 1;
    }
  }

  return (cap.first / (cap.second) * 1.0);
}

int main()
{
  return 0;
}

/*
newBudget = 190 this number would be divisible by arr.size()

left = 190/5 =>

right => 190 



Previously this was our  sum of grant array was our grant
grantsArray = [2, 100, 50, 120, 1000],

=> we need to cahnge the gratn array
the way we do this is have a cap
=> [2, 50, 100, 120, 1000]
=> [2, 50, 100, 120, 1000]

we have a new budget => 190

we need to change the grant array such that new budget is 190



/*

bool isPossible(int cap, vector<int> arr)
{
  if()
}


double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  sort(grantArray.begin(), grantArray.end());
  int n = grantsArray.size();
  int l = newBudget/n;
  int r = newBudget;
  
  
  while(l < r)
  {
    int mid = unsigned(l+r)/2;
    if(isPossible(mid, grantArray))
      l = mid+1;
    else 
      r = mid;
  }
  return l;
  // your code goes here
}
*/