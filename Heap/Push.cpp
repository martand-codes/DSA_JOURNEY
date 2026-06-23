// Pushing in the Heap

// We design Heap with the help of Vector or array to reduce the time complexities

class Heap {
    vector<int> vec; // Complete Binary Tree

    public:

        // Pushing

        void push(int value) {
            // Step 1
            vec.push_back(val);

            //Step 2: Reconfiguring the heap
            int x = vec.size()-1; // Child Index in 0 based indexing
            int pI = (x-1) / 2; // Parent Index

            while(pi >= 0 && vec[x] > vec[pI]) {
                swap(vec[x], vec[pI]);
                x = pI; // Updating Child Index
                pI = (x - 1) / 2;
            }
        }
}

int top() {
    return vec[0]; // Max Heap
}

bool empty () {
    return vec.size() == 0;
}