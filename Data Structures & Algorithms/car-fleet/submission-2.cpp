class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> posSpeed;
        for(int i = 0; i < n; i++) {
            posSpeed.push_back({position[i], speed[i]});
        }

        sort(posSpeed.rbegin(), posSpeed.rend());
        
        stack<double> st; // double because handle fractions
        for(int i = 0; i < n; i++) {
            double time = (double)(target-posSpeed[i].first)/posSpeed[i].second;
            if(st.empty() || st.top() < time) {
                st.push(time);
            }
        }

        return st.size();
    }
};

// 4  1  0  7
// 2  2  1  1

// 7 4 1 0
// 1 2 2 1

// 3 3 4 10


// 3
// 