/*
------------------------------------------------------------
Problem : Count Servers That Communicate (LeetCode 2747)
Pattern : Sorting + Offline Queries + Sliding Window

Time Complexity : O(L log L + Q log Q)
Space Complexity : O(L + Q + N)

Idea:
Sort the server logs by timestamp and sort the queries while
preserving their original indices.

Process queries in increasing order of time using a sliding
window [query_time - x, query_time].

Maintain the request count of each server inside the window
using server_counts. active_servers tracks the number of
servers having at least one request in the current window.

For every query, expand the right pointer to include logs
up to query_time and move the left pointer to remove logs
older than query_time - x.

The answer is the total number of servers minus the number
of active servers in the current window.

Key Insight:
Sorting queries allows us to reuse the sliding window
across multiple queries instead of independently scanning
all logs for every query.

Each log enters and leaves the window at most once, making
the window processing linear after sorting.
------------------------------------------------------------
*/



class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        vector<pair<int, int>> sorted_queries(q);
        for (int i = 0; i < q; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(q);
        vector<int> server_counts(n + 1, 0);
        int active_servers = 0;
        int left = 0;
        int right = 0;
        int num_logs = logs.size();
        
        for (const auto& query : sorted_queries) {
            int end_time = query.first;
            int start_time = end_time - x;
            int original_index = query.second;
            while (right < num_logs && logs[right][1] <= end_time) {
                int server_id = logs[right][0];
                if (server_counts[server_id] == 0) {
                    active_servers++;
                }
                server_counts[server_id]++;
                right++;
            }
            while (left < right && logs[left][1] < start_time) {
                int server_id = logs[left][0];
                server_counts[server_id]--;
                if (server_counts[server_id] == 0) {
                    active_servers--;
                }
                left++;
            }
            ans[original_index] = n - active_servers;
        }
        
        return ans;
    }
};