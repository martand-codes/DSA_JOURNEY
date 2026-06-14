// Approach:
//we just need to find the absolute difference so just sort the arrays
// Go through the loop use abs f(x) for the mod answer and just substract and add

// Problem: Minimum Sum of Absolute Differences
// Pattern: Greedy
// TC: O(n log n)
// SC: O(1) excluding sorting space

int minAbsoluteDifference(vector<int> Arr1, vector<int> Arr2) {
    sort(Arr1.begin(), Arr1.end());
    sort(Arr2.begin(), Arr2.end());

    int absoluteDifference = 0;
    int n = Arr1.size(); // We can take any one as the sizes are the same
    for(int i = 0; i < n; i++){
        absoluteDifference += abs(Arr1[i] - Arr2[i]);
    }
    return absoluteDifference;
}