#include <iostream>
#include <queue>

using namespace std; // Add the 'using namespace std' directive

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int key) : data(key), left(nullptr), right(nullptr) {}
};

Node* createBinaryTree() {
    int data;
    cout << "Enter data for the root node: ";
    cin >> data;
    Node* root = new Node(data);

    // Use a queue for level-order (breadth-first) construction
    queue<Node*> nodeQueue;

    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        Node* current = nodeQueue.front();
        nodeQueue.pop();

        int leftData, rightData;
        cout << "Enter data for the left child of " << current->data << " (or -1 for no child): ";
        cin >> leftData;
        if (leftData != -1) {
            current->left = new Node(leftData);
            nodeQueue.push(current->left);
        }

        cout << "Enter data for the right child of " << current->data << " (or -1 for no child): ";
        cin >> rightData;
        if (rightData != -1) {
            current->right = new Node(rightData);
            nodeQueue.push(current->right);
        }
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

void preorderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int countLeafNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = createBinaryTree();

    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    int leafCount = countLeafNodes(root);
    cout << "Number of Leaf Nodes: " << leafCount << endl;

    return 0;
}
