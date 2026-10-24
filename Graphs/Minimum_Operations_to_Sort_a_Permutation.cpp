class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }
        bool is_forward = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos + i) % n] != i) {
                is_forward = false;
                break;
            }
        }
        bool is_backward = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos - i + n) % n] != i) {
                is_backward = false;
                break;
            }
        }
        
        if (!is_forward && !is_backward) {
            return -1;
        }
        
        vector<int> dist(2 * n, -1);
        queue<pair<int, int>> q;
        
        if (is_forward) {
            q.push({pos, 0});
            dist[0 * n + pos] = 0;
        }
        
        if (is_backward && dist[1 * n + pos] == -1) {
            q.push({pos, 1});
            dist[1 * n + pos] = 0;
        }
        
        while (!q.empty()) {
            auto [p, dir] = q.front();
            q.pop();
            if (p == 0 && dir == 0) {
                return dist[dir * n + p];
            }
            int next_p1 = (p - 1 + n) % n;
            int next_dir1 = dir;
            int state1 = next_dir1 * n + next_p1;
            
            if (dist[state1] == -1) {
                dist[state1] = dist[dir * n + p] + 1;
                q.push({next_p1, next_dir1});
            }
            int next_p2 = n - 1 - p;
            int next_dir2 = 1 - dir;
            int state2 = next_dir2 * n + next_p2;
            
            if (dist[state2] == -1) {
                dist[state2] = dist[dir * n + p] + 1;
                q.push({next_p2, next_dir2});
            }
        }
        
        return -1;
    }
};