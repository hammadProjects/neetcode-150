/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> created;

        return dfs(node, created);
    }

    Node* dfs(Node* node, unordered_map<int, Node*>& created) {
        if(!node) return node;
        if(created.count(node->val)) {
            return created[node->val];
        }

        Node* newNode = new Node(node->val);
        created[node->val] = newNode;
        for(Node* n: node->neighbors) {
            Node* cur = dfs(n, created);
            if(cur) {
                newNode->neighbors.push_back(cur);
            }
        }

        return newNode;
    }
};