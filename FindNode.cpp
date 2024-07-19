#include <iostream>
#include <queue>

using namespace std;
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

Node* findParent(Node* root, int target, Node* parent = nullptr) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == target) {
        return parent;
    }

    Node* leftParent = findParent(root->left, target, root);
    if (leftParent != nullptr) {
        return leftParent;
    }

    return findParent(root->right, target, root);
}

int findDepth(Node* root, int target, int depth) {
    if (root == nullptr) {
        return -1;
    }

    if (root->data == target) {
        return depth;
    }

    int leftDepth = findDepth(root->left, target, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }

    int rightDepth = findDepth(root->right, target, depth + 1);
    return rightDepth;
}

void printAncestors(Node* root, int target) {
    if (root == nullptr) {
        return;
    }

    if (root->data == target) {
        return;
    }

    if (findDepth(root->left, target, 0) != -1 || findDepth(root->right, target, 0) != -1) {
        cout << root->data << " ";
    }

    printAncestors(root->left, target);
    printAncestors(root->right, target);
}

int main() {
    Node* root = createBinaryTree();

    int target;
    cout << "Enter the element for which you want to find the parent: ";
    cin >> target;

    Node* parent = findParent(root, target);
    if (parent != nullptr) {
        cout << "Parent of " << target << " is: " << parent->data << endl;
    } else {
        cout << "Element not found or is the root." << endl;
    }

    int depth = findDepth(root, target, 0);
    if (depth != -1) {
        cout << "Depth of " << target << " is: " << depth << endl;
    } else {
        cout << "Element not found in the tree." << endl;
    }

    cout << "Ancestors of " << target << " are: ";
    printAncestors(root, target);
    cout << endl;

    return 0;
}
