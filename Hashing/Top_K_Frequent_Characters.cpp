class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (const auto& pair : count) {
            buckets[pair.second].push_back(pair.first);
        }
        
        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        
        return ans;
    }
};