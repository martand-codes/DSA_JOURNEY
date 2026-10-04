/*
------------------------------------------------------------
Problem : Minimum Interval to Include Each Query (LeetCode 1851)
Pattern : Intervals + Sorting + Min Heap

Time Complexity : O((N + Q) log N)
Space Complexity : O(N + Q)

Idea:
- Sort intervals by their starting point.
- Store each query along with its original index and sort
  the queries in ascending order.
- Process queries from smallest to largest.
- For each query:
    - Add all intervals whose start <= query to the min heap.
    - The heap stores {intervalSize, intervalEnd}.
    - Remove intervals whose end < query because they no
      longer contain the current query.
    - The smallest interval remaining in the heap is the
      answer for the current query.
- Use the original query index to place the answer back
  in the required order.

Key Insight:
Because queries are processed in increasing order, once an
interval's start is <= the current query, it will also be
eligible for every future query (until it expires).

The min heap keeps the smallest valid interval on top.

An interval [left, right] contains query x when:

    left <= x <= right

Its size is:

    right - left + 1

Therefore, the heap orders valid intervals by their size,
while the end value lets us efficiently remove expired
intervals.

------------------------------------------------------------
*/


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = intervals.size();
        int n = queries.size();
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries(n);
        for (int i = 0; i < n; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> result(n);
        int i = 0;
        for (const auto& q : sortedQueries) {
            int queryVal = q.first;
            int originalIdx = q.second;
            while (i < m && intervals[i][0] <= queryVal) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                int size = right - left + 1;
                minHeap.push({size, right});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < queryVal) {
                minHeap.pop();
            }
            if (minHeap.empty()) {
                result[originalIdx] = -1;
            } else {
                result[originalIdx] = minHeap.top().first;
            }
        }

        return result;
    }
};