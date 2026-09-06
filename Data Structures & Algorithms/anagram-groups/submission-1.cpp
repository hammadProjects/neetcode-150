class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string s: strs) {
            string org = s;
            sort(s.begin(), s.end());
            groups[s].push_back(org);
        }

        vector<vector<string>> ans;
        for(auto& grp: groups) {
            ans.push_back(grp.second);
        }

        return ans;
    }
};