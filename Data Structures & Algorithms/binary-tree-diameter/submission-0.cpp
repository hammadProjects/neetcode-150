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

/*
Intution:
What max height i can get from left
What max height i can get from right

add the left + right because this is where we can move from one node to other

add it to a global variable
because height will give either max from left and right
*/

class Solution {
public:
    int height(TreeNode* root, int& ans) {
        if(!root) return 0;
        int left = height(root->left, ans);
        int right = height(root->right, ans);

        int sum = left + right;
        ans = max(ans, sum);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }
};