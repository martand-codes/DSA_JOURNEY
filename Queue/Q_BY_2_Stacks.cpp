class Queue {
    stack<int> S1;
    stack<int> S2;

    public:
        void push(int value){  // For O(n)
            /* 3 Steps Process
               1 Push in Stack1
               2 Pop from Stack1 and push in Stack2
               3 Pop from Stack2 and then push in Stack 1
            */

            // S1 -> S2
            while(!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
            S1.push(value);

            // S2 -> S1
            while (!S2.empty()) {
                S1.push(S2.top());
                S2.pop();
            }
        }

        void pop() { // O(1)
            if(S1.empty()) {
                cout << "Queue is Empty!\n";
                return;
            }
            S1.pop(); // We know that the final Stack is Stack 1
        }
        int front() { // O(1)
            return S1.top();
        }
};