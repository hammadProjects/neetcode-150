class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        unordered_set<int> toDelete;
        vector<pair<int, char>> stack;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch != '(' && ch != ')') continue;
            if(ch == '(') {
                stack.push_back({i, ch});
                continue;
            }

            if(ch == ')' && !stack.empty() && stack.back().second == '(')
                stack.pop_back();
            else {
                toDelete.insert(i);
                cout << i << "TO Delete" << endl;
            }
        }

        while(!stack.empty()) {
            pair<int, char> cur = stack.back();
            stack.pop_back();

            toDelete.insert(cur.first);
        }

        for(int i = 0; i < s.size(); i++) {
            cout << toDelete.count(i) << endl;
            if(toDelete.count(i) == 0) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};