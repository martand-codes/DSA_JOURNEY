/*
------------------------------------------------------------
Problem : Majority Element II (LeetCode 229)
Pattern : Hashing + Frequency Counting

Time Complexity : O(N)
Space Complexity : O(N)

Idea:
- Use an unordered_map to count the frequency of each
  number in the array.
- Traverse the frequency map after counting all elements.
- If a number appears more than N / 3 times, add it to
  the result.
- Return the result containing all qualifying elements.

Key Insight:
An element is a majority element if its frequency is
strictly greater than floor(N / 3).

There can be at most TWO such elements in an array,
because three elements each appearing more than N / 3
times would require more than N total occurrences.

The hash map allows us to count frequencies efficiently
without repeatedly scanning the array.

------------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int, int> counter;
        int n = nums.size();
        vector<int> result;
        for(int num : nums) {
            counter[num]++;
        }
        for(auto pair : counter) {
            int number = pair.first;
            int frequency = pair.second;
            if(frequency > n / 3) {
                result.push_back(number);
            }
        }
        return result; 
    }
};

/*
------------------------------------------------------------
Problem : Majority Element II (LeetCode 229)
Pattern : Boyer-Moore Voting Algorithm + Array

Time Complexity : O(N)
Space Complexity : O(1) auxiliary space

Idea:
- Since an element must appear more than N / 3 times,
  there can be at most two majority elements.
- Maintain two candidate values (cand1, cand2) and
  their respective counts (count1, count2).
- First pass:
    - If the current number matches cand1, increment count1.
    - Else if it matches cand2, increment count2.
    - Else if count1 is zero, assign cand1 to the number.
    - Else if count2 is zero, assign cand2 to the number.
    - Otherwise, decrement both counts.
- Second pass:
    - Reset the counts and count the actual occurrences
      of both candidates.
    - Include a candidate only if its frequency exceeds N / 3.

Key Insight:
Boyer-Moore Voting works by cancelling out different
candidate values against one another.

For the N / 3 threshold, at most two elements can appear
more than N / 3 times, so only two candidate slots are
necessary.

The first pass identifies potential candidates, but does
not guarantee they are majority elements. The second pass
verifies their actual frequencies.

------------------------------------------------------------
*/

// Boyer Moore Voting Algorithm:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;
        
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
        
        vector<int> result;
        if (count1 > n / 3) result.push_back(cand1);
        if (count2 > n / 3) result.push_back(cand2);
        
        return result;
    }
};