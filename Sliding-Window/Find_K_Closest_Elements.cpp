/*
------------------------------------------------------------
Problem : Find K Closest Elements (LeetCode 658)

Pattern : Heap / Priority Queue / Min Heap /
          Sorting / Distance-Based Selection

Time Complexity :
FindClosestElements : O(N + K log N + K log K)

Space Complexity : O(N)

Idea:
Find the k elements in the sorted array that are closest
to the given integer x and return them in ascending order.

- Initialize an empty vector ans to store the k closest
  elements.
- Create a min heap using a priority queue of pairs:
  - The first element represents the absolute difference
    between an array element and x.
  - The second element represents the actual array value.
- Use greater<pair<int,int>> to maintain ascending order
  based on the pair values.

Building the Min Heap:
- Traverse every element of the input array.
- Calculate its absolute difference from x using
  abs(arr[i] - x).
- Insert the pair {abs(arr[i] - x), arr[i]} into
  the min heap.
- The min heap automatically prioritizes:
  - Smaller absolute differences.
  - Smaller array values when distances are equal.

Extracting K Closest Elements:
- Repeat the extraction process until k elements
  have been selected.
- Retrieve the element at the top of the min heap.
- Append its actual array value to ans.
- Remove the extracted element from the min heap.

Final Sorting:
- Sort ans in ascending order because the extraction
  order is based on distance rather than array value.

Finally:
- Return ans containing the k closest elements
  in ascending order.

Key Insight:
A min heap can efficiently select elements based on
their distance from the target x.

Using pairs allows the priority queue to automatically
handle tie-breaking.

When two elements have the same absolute difference
from x, the smaller element receives higher priority
because pair comparison considers the second element
when the first elements are equal.

The heap extracts the k elements with the smallest
distance values, and sorting the selected elements
ensures the required ascending output order.

N represents the number of elements in the input array.
K represents the number of closest elements required.

Inserting all N elements into the priority queue
requires O(N log N) time.

Extracting K elements requires O(K log N) time
because each heap removal takes O(log N) time.

Sorting the resulting K elements requires O(K log K)
time.

Therefore, the overall time complexity is
O(N log N + K log N + K log K).

The priority queue stores all N elements, requiring
O(N) auxiliary space.

The answer vector stores K elements, requiring O(K)
additional space.

------------------------------------------------------------
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        while(k>0)
        {
            k--;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

};