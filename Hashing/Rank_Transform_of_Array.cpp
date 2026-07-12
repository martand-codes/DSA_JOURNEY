// Problem: Rank Transform of an Array (LeetCode 1331)
// Pattern: Sorting + Hash Map
// TC: O(n log n)
// SC: O(n)
//
// Idea:
// Copy and sort the array.
// Assign increasing ranks to unique values.
// Use a hash map to remember each value's rank.
// Build the answer using the original array.

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = rankMap[arr[i]];
        }
        
        return result;
    }
};