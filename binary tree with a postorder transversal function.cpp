#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform postorder traversal
void postorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    // Traverse left subtree
    postorderTraversal(node->left);
    
    // Traverse right subtree
    postorderTraversal(node->right);
    
    // Visit the node (process current node)
    cout << node->val << " ";
}

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform postorder traversal
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}