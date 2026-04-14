class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(st.empty() || temperatures[st.top()] > temperatures[i]) {
                st.push(i);
                cout << "Coming here for what value?" << st.top() << endl;
                continue;
            }

            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int curr = st.top();
                st.pop();

                res[curr] = i - curr;
            }

            st.push(i);
        }

        return res;
    }
};
// [30]

/*
i = 0: [30]
i = 1: 38 > 30 [38]
i = 2: [38, 30]
i = 3: 36 > 30, [38] 36 > 38 [38, 36]
i = 4: 35 > 36 [38, 36, 35]
i = 5: 40 > 35, [38, 36] 40 > 36, [38], 40 > 38 [40]
i = 6: 28 > 40 [40, 28]
*/