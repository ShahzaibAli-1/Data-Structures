#include <iostream>

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for the binary tree
class BinaryTree {
private:
    Node* root;

    // Helper function to insert a value into the tree
    Node* insert(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return new Node(value);
        }

        if (value < currentNode->data) {
            currentNode->left = insert(currentNode->left, value);
        } else {
            currentNode->right = insert(currentNode->right, value);
        }

        return currentNode;
    }

    // Helper function to perform an in-order traversal
    void inorderTraversal(Node* currentNode) {
        if (currentNode != nullptr) {
            inorderTraversal(currentNode->left);
            std::cout << currentNode->data << " ";
            inorderTraversal(currentNode->right);
        }
    }

public:
    // Constructor to initialize an empty tree
    BinaryTree() : root(nullptr) {}

    // Function to insert a value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to perform an in-order traversal of the tree
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Perform an in-order traversal
    std::cout << "In-order traversal: ";
    tree.inorderTraversal();

    return 0;
}
