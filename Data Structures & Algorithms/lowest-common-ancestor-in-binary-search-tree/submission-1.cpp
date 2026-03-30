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
    TreeNode* ans;
    void findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) {
            ans = root;
        }

        if(root->val > p->val) {
            findLCA(root->left, p, q);
        } else if(root->val < q->val) {
            findLCA(root->right, p, q);
        } else {
            ans = root;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        if(p->val > q->val) {
            findLCA(root, p, q);
        } else {
            findLCA(root, q, p);
        }
        return ans;
    }
};
