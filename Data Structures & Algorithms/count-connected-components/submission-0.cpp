class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        int connected_components = 0;
        for(auto& edge: edges) {
            int first = edge[0];
            int second = edge[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        for(int node = 0; node < n; node++) {
            if(!vis[node]) {
                connected_components++;
                dfs(node, adj, vis);
            }
        }

        return connected_components;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        if(vis[node]) return;
        vis[node] = true;

        for(auto& ngbr: adj[node]) {
            if(!vis[ngbr]) dfs(ngbr, adj, vis);
        }
    }
};

/*
        0: [1],
        1: [0,2],
        2: [1],
        3: [4],
        4: [3],
        */