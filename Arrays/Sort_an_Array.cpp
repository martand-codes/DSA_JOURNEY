/*
------------------------------------------------------------
Problem : Sort an Array (LeetCode 912)
Pattern : Sorting / Divide and Conquer (Merge Sort)

Time Complexity : O(N log N)
Space Complexity : O(N)

Idea:
- Recursively divide the array into two halves until
  each subarray contains at most one element.
- Sort both halves recursively.
- Merge the two sorted halves into a single sorted array.
- Use a temporary array during the merge process.

Key Insight:
Merge Sort works because two already sorted halves can be
combined in linear time. The array is divided into O(log N)
levels, and each level processes O(N) elements.

------------------------------------------------------------
*/

/*
------------------------------------------------------------
Problem : Sort an Array (LeetCode 912)
Pattern : Sorting / Divide and Conquer (Quick Sort)

Time Complexity : O(N log N) Average, O(N²) Worst Case
Space Complexity : O(log N) Average Recursion Stack

Idea:
- Choose a random element as the pivot.
- Partition the array into three regions:
    1. Elements smaller than the pivot
    2. Elements equal to the pivot
    3. Elements greater than the pivot
- Recursively sort the smaller and greater regions.
- Randomized pivot selection helps reduce the chance of
  consistently poor partitions.

Key Insight:
Partitioning places the pivot's equal elements into their
final relative region while reducing the problem into two
smaller independent sorting problems. Three-way partitioning
is especially effective when duplicate values are common.

------------------------------------------------------------
*/

/*
------------------------------------------------------------
Problem : Sort an Array (LeetCode 912)
Pattern : Sorting / Counting Sort

Time Complexity : O(N + K)
Space Complexity : O(K)

Idea:
- Find the minimum and maximum values in the array.
- Create a frequency array covering the entire value range.
- Use an offset (minVal) so negative values can also be
  represented as valid indices.
- Count the frequency of every number.
- Traverse the frequency array and reconstruct the sorted
  array in increasing order.

Key Insight:
When the range of possible values is reasonably small,
sorting can be replaced by frequency counting. Instead of
comparing elements, count how many times each value occurs
and reconstruct the sorted array from those frequencies.

------------------------------------------------------------
*/


// Merge Sort
class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];
        
        for (int p = 0; p < k; ++p) {
            nums[left + p] = temp[p];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Quick Sort
class Solution {
private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];
        
        int i = left, lt = left, gt = right;
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i++], nums[lt++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
        }
        
        quickSort(nums, left, lt - 1);
        quickSort(nums, gt + 1, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};


// Counting Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minVal = 50000;
        int maxVal = -50000;
        
        for (int num : nums) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }
        
        vector<int> counts(maxVal - minVal + 1, 0);
        for (int num : nums) {
            counts[num - minVal]++;
        }
        
        int index = 0;
        for (int i = 0; i < counts.size(); ++i) {
            while (counts[i] > 0) {
                nums[index++] = i + minVal;
                counts[i]--;
            }
        }
        
        return nums;
    }
};