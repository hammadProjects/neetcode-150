struct cmp {
    bool operator() (vector<int>& a, vector<int>& b) {
        int x0 = 0, x1 = a[0], x2 = b[0];
        int y0 = 0, y1 = a[1], y2 = b[1];

        int dist1 = x1*x1 + y1*y1;
        int dist2 = x2*x2 + y2*y2;

        return dist1 > dist2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        vector<vector<int>> ans;
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            cmp
        > pq;

        for(vector<int>& pnt: points) {
            pq.push(pnt);
        }

        for(int i = 1; i <= k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};