class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char ch: s) {
            // stack empty or top have different element then push
            if(st.empty() || st.top().first != ch) {
                pair<char, int> curr = {ch, 1};
                cout << curr.first << " " << curr.second << endl;
                st.push(curr);
            } else {
                pair<char, int> curr = {ch, st.top().second + 1};
                st.push(curr);
                cout << curr.first << " " << curr.second << endl;
            }

            // pop if the top's count is equal to k
            if(st.top().second == k) {
                cout << "Came here for which character? " << ch << endl;
                while(!st.empty() && st.top().first == ch) {
                    st.pop();
                }
            }
        }

        string res = "";
        while(!st.empty()) {
            res += st.top().first;
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// k = 3
// deeedbbcccbdaa