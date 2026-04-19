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
    int idx = 0;
    unordered_map<int, int> indices;
    TreeNode* build(vector<int>& preorder, int low, int high) {
        if(low > high) return nullptr;

        TreeNode* curr = new TreeNode(preorder[idx++]);
        if(low == high) return curr;

        int id = indices[preorder[idx - 1]];
        curr->left = build(preorder, low, id - 1);
        curr->right = build(preorder, id + 1, high);

        return curr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};

// get root from preorder at each level
// look for that root in inorder
// on left part of root in inorder is left subtree and on right is right one