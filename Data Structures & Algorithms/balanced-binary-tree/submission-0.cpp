/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        if(!root) return {1, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        int balanced = (left[0]) && (right[0]) && (abs(left[1] - right[1]) <= 1);
        int height = max(left[1], right[1]) + 1;
        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];
    }
};
