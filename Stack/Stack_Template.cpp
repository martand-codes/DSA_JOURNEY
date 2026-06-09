#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

template<class T>  // Initializing the template
class Stack {
    vector<T> vec;
    public:
        void push(T val) {
            vec.push_back(val);
        }
        void pop() {
            if(isEmpty()) {
                cout<<"Stack is Empty!";
                return;
            }
            vec.pop_back();
        }
        T top() {
            if (isEmpty()) {
                throw runtime_error("Stack is Empty!");
            }
            int lastIndex = vec.size() - 1;
            return vec[lastIndex];
        }
        bool isEmpty() {
            return vec.size() == 0;
        }
        void print() {
            if(isEmpty()) {
                cout << "Stack is Empty!\n";
                return;
            }
            for(int i = vec.size() - 1; i >= 0; i--) {
                cout << vec[i] << " ";
            }
            cout << endl;
        }
        // Push at Bottom using STL and Recursion
        void pushAtBottom(&stack<int>& s, int value) { // We have given reference becuase we want to reflect this on main
            // Base Case
            if(s.empty()) {
                s.push(value);
                return;
            }
            int temp = s.top();
            s.pop();
            pushAtBottom(s, value);
            s.push(temp);
        }
        void reverseStack(stack<int>& s) {
            // Base Case:
            if (s.empty()) {
                return;
            }
            int temp = s.top();
            s.pop();
            reverseStack(s);
            pushAtBottom(s, temp); // Because in normal push it will again write the same stack while backtracking
        }
};

int main() {
    Stack<char>S; // We can write any datatype in this and perform the operations

}