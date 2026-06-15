// Making the Node

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        // Constructor
        Node (int data) {
            this->data = data;
            left = right = NULL;
        }

};

static int index = -1;

Node* buildTree(vector<int>& nodes) {
    index++;
    // Base Case: If there are no Nodes
    if (nodes[index] == -1) {
        return NULL;
    }
    // Building New Node
    Node* currentNode = new Node(nodes[index]);
    // We will Simply Recurse for Left Then Right
    currentNode->left = buildTree(nodes);
    currentNode->right = buildTree(nodes);

    return currentNode; // The Root will be Returned
}



