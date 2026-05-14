// Problem: To determine whether an array contains duplicate elements

Brute Force 

Tc: O(n^2)
Sc: O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};



// Using Hashing!

// Tc: O(n)
// Sc: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> found;

        for(int num : nums) {

            if(found.find(num) != found.end()) {
                return true;
            }

            found.insert(num);
        }

        return false;
    }
};