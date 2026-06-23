// Popping in a Heap


void heapify (int pI) {
    // Base Case:
    if (pI >= vec.size()) {
        return;
    }

    int leftChild = 2 * pI + 1;
    int rightChild = 2 * pI + 2;

    int maxIndex = pI; // Initializing the maximum Index as Parent Index pI

    // for left Child 
    if(leftChild < vec.size() && vec[leftChild] > vec[maxIndex]) {
        maxIndex = leftChild;
    }
    if(rightChild < vec.size() && vec[rightChild] > vec[maxIndex]) {
        maxIndex = rightChild;
    }

    // Now Swap
    swap(vec[pI], vec[maxIndex]);

    if (maxIndex != pI) { // If Swapping is happening within children
        heapify(maxIndex);
    }
}

void pop() {
    // Step 1
    swap(vec[0], vec[vec.size() - 1]);  // Swapping the first and the last index

    // Step 2
    vec.pop_back(); // Delete the last index

    // Step 3
    heapify(0); // Call the Heapify Function for the root
}