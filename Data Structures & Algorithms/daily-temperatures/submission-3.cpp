class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // temperatures
        vector<int> res(n, 0);
        stack<int> st;
        st.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                res[i] = st.top() - i;
            }
            st.push(i);
        }

        return res;
    }
};

// [40] 35