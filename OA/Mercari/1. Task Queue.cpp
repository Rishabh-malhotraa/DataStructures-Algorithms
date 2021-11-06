#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY batchSize
 *  2. INTEGER_ARRAY processingTime
 *  3. INTEGER_ARRAY numTasks
 */
long minTime(vector<int> batchSize, vector<int> processingTime, vector<int> numTasks)
{
  int n = batchSize.size();

  long long processTime = LONG_LONG_MIN;

  for (int i = 0; i < n; i++)
  {
    long long batches = ceil((1.0 * numTasks[i]) / batchSize[i]);

    processTime = max(processTime, batches * processingTime[i]);
  }
  return processTime;
}
