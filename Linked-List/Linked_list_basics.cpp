// Linked List Basics

#include<iostream>
using namespace std;

// Creating Node Class 

class Node {
    
    public:
        int data;
        Node* next;
        Node(int value){
            data = value;
            next = NULL;
        }
    // Deconstructor
        ~Node() {
          // Left Empty to prevent Stack Overflow
        }
};

// Creating List Class = Collection of Nodes

class List {
    Node* head;
    Node* tail;

    public:
        List() {
            head = NULL;
            tail = NULL;
    }

    // Deconstructor
    ~List() {
        Node* temp = head;
        
        while (head != NULL) {
            head = head->next; // Safely move head to the next node
            delete temp;       // Delete the node we left behind
            temp = head;       // Catch temp up to the new head
        }
        
        // Optional: clear the tail pointer just to be safe
        tail = NULL; 
    }

    // Pushing Font

    void pushFront(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }  
    }

    // Pushing Rear

    // For O(1)
    void pushRear_constant(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // For O(n)
    void pushRear_Linear(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        } 
        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Inserting Anywhere
  void insert(int value, Node* position) {
    // 1. Edge Case: Empty list OR inserting right at the front
    if (head == NULL || position == head) {
        pushFront(value); 
        return;
    }
    
    Node *temp = head;
    
    // SAFE TRAVERSAL: Check temp != NULL *before* asking for temp->next
    while (temp != NULL && temp->next != position){
        temp = temp->next;
    }
    
    // 2. Edge Case: Check if we failed to find it BEFORE doing anything else
    if (temp == NULL) {
        cout << "Error: Target position not found in the list." << endl;
        return; 
    }
    
    // 3. NOW it is safe to create the node and do the pointer dance!
    Node* newNode = new Node(value);
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    // 4. Tail Maintenance
    if (newNode->next == NULL) {
        tail = newNode;
    }
}

    // Printing Function
    void print() {
        Node* temp = head;
        if(head == NULL) {
            cout<<"List is empty!!";
            return;
        }
        while(temp != NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<" -> NULL";
    }

    // Pop_front
    void popFront() {
        if (head == NULL) {
            cout<<"List is Empty";
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // pop_back: No Way of deletion in O(1) in a singly Linked List
    void popBack() {
        if (head == NULL) {
            cout<<"List is empty!";
            return;
        }
        if (head == tail) { 
            delete head;   // Smash the only box
            head = NULL;   // Erase the head sticky note
            tail = NULL;   // Erase the tail sticky note
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    // For Seraching Linearly
    int iterativeSearch(int key) {
        Node* temp = head;
        int index = 0;
        while (temp != NULL) {
            if (temp->data == key){
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // For Searching Recursively
    int helper(Node* temp, int key) {
        if (temp == NULL) {
            return -1;
        }
        
        if (temp->data == key) {
            return 0;
        }
        int index = helper(temp->next, key);
        if (index == -1) {
            return -1;
        }
        return index + 1;
    }
    
    int recursiveSearch(int key) {
       return helper(head, key);
    }

    // Reversing a List: We need 3 pointers Current Previous Next
    void reverseList() {
        // 1. Edge Case: Empty list or list with 1 node
        if (head == NULL || head->next == NULL) {
            return; // Nothing to reverse!
        }

        // 2. TAIL MAINTENANCE: The old head will become the new tail
        tail = head; 

        // 3. The Core Reversal Logic 
        Node* current = head;
        Node* previous = NULL;
        
        while (current != NULL) {
            Node* next = current->next; // Anchor the rest of the list
            current->next = previous;   // Flip the arrow backwards
            previous = current;         // Step 'previous' forward
            current = next;             // Step 'current' forward
        }
        
        // 4. Update the head to the new front of the list
        head = previous;
    }
};




