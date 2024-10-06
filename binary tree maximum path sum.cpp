#include <iostream>
#include <algorithm>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum path sum
int maxPathSumUtil(TreeNode* node, int &maxSum) {
    if (node == nullptr) {
        return 0;
    }

    // Recursively calculate the maximum path sum for left and right children
    int leftMax = max(maxPathSumUtil(node->left, maxSum), 0); // Only add positive contributions
    int rightMax = max(maxPathSumUtil(node->right, maxSum), 0); // Only add positive contributions

    // Calculate the maximum path sum including the current node
    int currentMax = node->val + leftMax + rightMax;

    // Update the global maximum sum if the current path sum is greater
    maxSum = max(maxSum, currentMax);

    // Return the maximum path sum "starting" from this node
    return node->val + max(leftMax, rightMax);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN; // Initialize to the smallest integer
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calculate maximum path sum
    int result = maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}