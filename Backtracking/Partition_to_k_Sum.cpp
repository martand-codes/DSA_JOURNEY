class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;
        
        int target = totalSum / k;
        sort(nums.rbegin(), nums.rend());
        
        if (nums[0] > target) return false;
        
        return backtrack(nums, k, target, 0, 0, 0);
    }

private:
    bool backtrack(const vector<int>& nums, int k, int target, int currentSum, int start, int used) {
        if (k == 1) return true;
        
        if (currentSum == target) {
            return backtrack(nums, k - 1, target, 0, 0, used);
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (((used >> i) & 1) || currentSum + nums[i] > target) continue;
            
            if (backtrack(nums, k, target, currentSum + nums[i], i + 1, used | (1 << i))) {
                return true;
            }
            
            if (currentSum == 0) return false;
            
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        
        return false;
    }
};