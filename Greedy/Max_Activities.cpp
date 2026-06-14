// Maximum Number of Activities using Greedy Approach

int maxActivities(vector<int> start, vector<int> end) {
    int counter = 1;
    int currentEnd = end[0]; // Assuming that End Vector is sorted

    for(int i = 1; i <= start.size(); i++) { // Traversing through the start loop
        
        // Greedy Condition Check

        if(start[i] >= currentEnd) {
            counter++;
            currentEnd = end[i];
        }
    }
    return counter;
}