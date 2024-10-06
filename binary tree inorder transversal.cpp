#include <iostream>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize a node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
void inorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return; // Base case: if the node is null, do nothing
    }

    // Traverse the left subtree
    inorderTraversal(node->left);
    
    // Visit the current node (process current node)
    cout << node->val << " ";
    
    // Traverse the right subtree
    inorderTraversal(node->right);
}

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1); // Root node
    root->left = new TreeNode(2);     // Left child
    root->right = new TreeNode(3);    // Right child
    root->left->left = new TreeNode(4);  // Left-left child
    root->left->right = new TreeNode(5); // Left-right child

    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}