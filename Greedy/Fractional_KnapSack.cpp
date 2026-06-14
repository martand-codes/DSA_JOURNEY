// Problem: Fractional Knapsack
// Pattern: Greedy
// TC: O(n log n)
// SC: O(n)

bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first; // Descending Order Based on their Ratios
}


int fractionalKnapsack(vector<int> value, vector<int> weight, int knapWeight) {
    int n = value.size(); // As both value and weight sizes are same we can take any one's
    // Making a pair for the first time
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0));  // making a pair of ratio and index and intializing them by 0 = pair(ratio, index)

    for(int i = 0; i < n; i++) {
        double r = value[i] / (double)weight[i];
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare); // Descending Order

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int index = ratio[i].second;
        // Main Logic
        if(weight[index] <= knapWeight) {
            ans += value[index];
            knapWeight -= weight[index];
        } else {
            ans += ratio[i].first * knapWeight;
            knapWeight = 0;
            break;  
        }
    }
    return ans;
}