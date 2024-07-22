#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftMax = std::max(0, maxPathSumHelper(node->left, maxSum)); 
        int rightMax = std::max(0, maxPathSumHelper(node->right, maxSum)); 

        
        int currentMax = node->val + leftMax + rightMax;

        
        maxSum = std::max(maxSum, currentMax);

        
        return node->val + std::max(leftMax, rightMax);
    }
};

int main() {
  
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.maxPathSum(root);
    std::cout << "Maximum path sum: " << result << std::endl;

    
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
