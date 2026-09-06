class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans = "";
        for(string s: strs) {
            ans += to_string(s.size());
            ans.push_back('#');
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.empty()) return ans;

        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int size = stoi(s.substr(i, j - i));
            
            ans.push_back(s.substr(j + 1, size));
            i = j + size + 1;
        }

        return ans;   
    }
};