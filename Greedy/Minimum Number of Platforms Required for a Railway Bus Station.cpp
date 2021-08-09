// Program to find minimum number of platforms
// required on a railway station
#include <algorithm>
#include <iostream>

using namespace std;

// Priority queue with distinciton between entry and exit times

// Returns minimum number of platforms required
int findPlatform(int arr[], int dep[], int n)
{

  // plat_needed indicates number of platforms
  // needed at a time
  int plat_needed = 1, result = 1;
  int i = 1, j = 0;

  // run a nested  loop to find overlap
  for (int i = 0; i < n; i++)
  {
    // minimum platform
    plat_needed = 1;

    for (int j = i + 1; j < n; j++)
    {
      // check for overlap
      if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
          (arr[j] >= arr[i] && arr[j] <= dep[i]))
        plat_needed++;
    }

    // update result
    result = max(result, plat_needed);
  }

  return result;
}

// Driver Code
int main()
{
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Minimum Number of Platforms Required = "
       << findPlatform(arr, dep, n);
  return 0;
}