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

class Codec {
public:
    void bfs(TreeNode* root, string& res) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr == nullptr) {
                    res += "n,";
                } else {
                    res += to_string(curr->val);
                    res += ',';
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
    }

    TreeNode* debfs(string data) {
        queue<TreeNode*> q;
        // get root
        int i = 0;
        string rootVal = "";
        while(data[i] != ',') {
            rootVal += data[i++];
        }
        i++;

        TreeNode* root = new TreeNode(stoi(rootVal));
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // left
            string left = "";
            while(data[i] != ',') {
                left += data[i++];
            }
            i++;

            if(left != "n") {
                curr->left = new TreeNode(stoi(left));
                q.push(curr->left);
            }

            // right
            string right = "";
            while(data[i] != ',') {
                right += data[i++];
            }
            i++;

            if(right != "n") {
                curr->right = new TreeNode(stoi(right));
                q.push(curr->right);
            }
        }

        return root;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        string res;
        bfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "n") return nullptr;
        return debfs(data);
    }
};
