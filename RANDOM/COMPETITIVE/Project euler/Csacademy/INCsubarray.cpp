/*
INCREASING SUBARRAYS

You are given an array of
N integers. On each element of the array you can apply the following operation: increment its value by
1. You are allowed to apply multiple operations on the same element.
You should count the number of sub-arrays respecting the following property: they can be made monotonic increasing using at most
M operations.

TEST CASES
------------
6 6
5 4 1 1 5 5
output 18

5 3
5 4 3 2 1
output 12

10 35
6 1 10 2 7 3 9 4 8 5
output 54
EDITORIAL
For each index i we want to find a value answer[i] representing the largest index j such that the subsequence determined by these indices
can be made monotonic increasing by using at most M operations.

Let's denote by v the array given as input. We preprocess partial sums over v so we can find out quickly the sum of the elements for a given subarray.
 We also preprocess another array next, where next[i] represents the smallest index j such that v[i] < v[j]. This can be accomplished in linear time using a stack.

We can come up with a simple brute force solution.
For a fixed starting index i we want to make all the elements between i and next[i]-1 equal to v[i],
all the elements between next[i] and next[next[i]]-1 equal to v[next[i]], and so on as long as the number of operations needed doesn't exceed M.

Let's try to optimize this algorithm by using the information computed for i when trying to find the answer for i-1. We distinguish two cases:
v[i-1] ≤ v[i]: Nothing really changes, answer[i-1] is identical to answer[i]
v[i-1] > v[i]: On all the elements between i and next[i-1] we should perform an extra v[i-1]-v[i] operations.
This means that answer[i-1] will be smaller than answer[i].

We can use a deque to store the values i, next[i], next[next[i]], and so on.
When we want to decrement the starting index to i-1 we pop front values from the deque until we get to next[i-1].
Then we pop back values while the number of operations needed is larger than M.
*/




