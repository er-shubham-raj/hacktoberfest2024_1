#include <iostream>
using namespace std;

// Node class for the Binary Search Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper function for inserting a node
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Helper function to find the minimum node
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deleting a node
    Node* deleteNode(Node* root, int val) {
        if (root == nullptr) return root;

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Insert a value in the BST
    void insert(int val) {
        root = insert(root, val);
    }

    // Delete a value from the BST
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // Inorder traversal of the BST
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    tree.deleteNode(20);
    cout << "After deleting 20: ";
    tree.inorder();

    tree.deleteNode(30);
    cout << "After deleting 30: ";
    tree.inorder();

    tree.deleteNode(50);
    cout << "After deleting 50: ";
    tree.inorder();

    return 0;
}
