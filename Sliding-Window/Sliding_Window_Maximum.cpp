/*
------------------------------------------------------------
Problem : Sliding Window Maximum (LeetCode 239)
Pattern : Sliding Window / Monotonic Deque /
          Array / Decreasing Order Maintenance

Time Complexity :
MaxSlidingWindow : O(N)

Space Complexity : O(K)

Idea:
Find the maximum element in every contiguous subarray
(window) of size k using a deque to efficiently maintain
potential maximum elements.

- Initialize a deque dq to store indices of array
  elements in decreasing order of their values.
- Initialize an empty result vector to store the maximum
  element of each sliding window.

First Window Initialization:
- Traverse the first k elements of the array.
- Before inserting the current index:
  - Remove indices from the back of the deque while
    their corresponding values are less than or equal
    to the current element.
  - These elements can never become maximum in any
    future window because the current element is
    greater than or equal to them and appears later.
- Insert the current index at the back of the deque.

Processing Remaining Windows:
- Traverse the remaining elements starting from index k.
- The front of the deque contains the index of the
  maximum element in the previous window.
- Add nums[dq.front()] to the result vector.
- Remove indices from the front while they are outside
  the current window:
  - An index is expired when dq.front() <= i - k.
- Maintain the decreasing order of elements:
  - Remove indices from the back while their
    corresponding values are less than or equal
    to the current element.
- Insert the current index at the back of the deque.

Finally:
- After processing all remaining elements, append the
  maximum element of the last window using dq.front().
- Return the result vector containing the maximum
  element of every window.

Key Insight:
The deque maintains indices of elements in monotonically
decreasing order of their corresponding values.

The front of the deque always represents the maximum
element within the current sliding window.

Removing smaller or equal elements from the back ensures
that unnecessary candidates are discarded because a
newer element with a greater or equal value will remain
in the window longer.

Removing expired indices from the front ensures that
only elements belonging to the current window are
considered.

Each array index is inserted into the deque exactly once
and removed at most once, either from the front or back.

Therefore, although deque operations occur inside loops,
the total number of deque operations across the entire
algorithm is O(N), resulting in linear time complexity.

N represents the number of elements in the input array.
K represents the sliding window size.

The deque stores at most k indices because only elements
belonging to the current window are maintained.

The result vector stores N - K + 1 maximum elements.

The auxiliary deque requires O(K) space, excluding the
output vector.

------------------------------------------------------------
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for(int i = 0; i < k; i++) {
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i = k; i < nums.size(); i++) {
            result.push_back(nums[dq.front()]);

            while(dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        return result;
        
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove the element that is out of the current window's bounds
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. Remove all smaller elements (they can never be the maximum)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add the current element's index
            dq.push_back(i);
            
            // 4. Once we have processed at least 'k' elements, start recording the max
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};