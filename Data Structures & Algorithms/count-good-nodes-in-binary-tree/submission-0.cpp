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
    void count(TreeNode* root, int maxi, int& n) {
        if(!root) return;
        if(maxi <= root->val) {
            n++;
        }

        count(root->left, max(maxi, root->val), n);
        count(root->right, max(maxi, root->val), n);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int n = 0;
        count(root, root->val, n);
        return n;
    }
};
