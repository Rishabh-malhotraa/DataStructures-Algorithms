
# Monotonic Queue

Hope it helps.

The following question can be solved by monotonic queue:

- **LC84. Largest Rectangle in Histogram**
- **LC239. Sliding Window Maximum**
- **LC739. Daily Temperatures**
- **LC862. Shortest Subarray with Sum at Least K**
- **LC901. Online Stock Span**
- **LC907. Sum of Subarray Minimums**

In general, the following "prototype" problems can be solved by monotonic queue:

## Any DP problem where  `A[i] = min(A[j:k]) + C`  where  `j < k <= i`

This is a sliding max/min window problem.

The task is to return the max/min elements in some sliding window. For example, we want a running max in the sliding windows,  `amax = max(A[i:i+width])`.

Key observation: Given input array  `A`, when  `A[l] < A[r]`  for  `l < r`, then  `A[l]`  should never be retuned as the sliding max  `amax`, once  `A[r]`  has entered the sliding window.

So we maintain a monotonic array with index  **increasing**  and value  **decreasing**, because smaller elements like  `A[l]`  on the left are useless.

For example, with sliding window of fixed length 3,

> `A = [3, 1, 4, 3, 8] => monotonic queue is like [3], [3, 1], [4], [4, 3], [8]`  
> when element  `4`  enters, we remove  `[3, 1]`  because they are on the left and smaller than  `4`, no chance being chosen as the max element.

The head of the increasing queue is the running max!

The only unique thing here is that we can keep the elements in the window sorted. It brings great benefits because it takes O(1) to obtain the min/max element in the window.

That's why any DP problem where  `A[i] = min(A[j:k]) + C`  for  `j < k <= i`  and some constant  `C`  can be solved by Monotonic Queue.

## Find the nearest larger element on the left

Given array  `A`  and an element  `A[i]`, the task is to find the maximum index  `j < i`  such that  `A[j] > A[i]`. Namely,  `A[j]`  is the nearest larger element on the left of  `A[i]`.

Key observation: given  `A[k] < A[j] > A[i]`  for  `k < j < i`,  `A[k]`  never become the  **nearest**  element larger than  `A[i]`  because of  `A[j]`.

So we should have a decreasing monotonic queue here. The arrow indicates that the mapping from element on the right to the nearest element on the left larger than it. The elements in the valley are ignored.

![alt text](https://imgur.com/ZfQSOag.png=10x2)