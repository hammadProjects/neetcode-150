class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int res;
                if(s == "+") {
                    res = second + first;
                } else if(s == "-") {
                    res = second - first;
                } else if(s == "*") {
                    res = second * first;
                } else {
                    res = second / first;
                }

                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
