/*

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm

        int n = nums.size();
        int ans = 0;
        int freq = 0;
        for (int i = 0; i < n; i++){
            if (freq == 0){
                ans = nums[i];
            }
            if (ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans;
    }
};

*/

// Solved Using Hashing

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m; // Storing Element And Frequency

        for(int i = 0; i < nums.size(); i++) {
           /* if(m.count(nums[i])) {
                m[nums[i]]++; //If already Present Increase the Frequency
            } else {
                m[nums[i]] = 1; // If not initilize it by 1
            }
        }
        */ // Cpp Handles the keys Automatically
            m[nums[i]]++;
        }
        for(pair<int, int> p : m) {
            if (p.second > nums.size() / 2) {
                return p.first;
            }
        }
        return 0;
    }
};

