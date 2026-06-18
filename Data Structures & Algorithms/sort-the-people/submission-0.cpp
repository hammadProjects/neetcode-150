class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> name_heights;
        for(int i = 0; i < n; i++) {
            name_heights.push_back({heights[i], names[i]});
        }

        sort(name_heights.rbegin(), name_heights.rend());
        vector<string> res;
        for(auto& cur: name_heights)
            res.push_back(cur.second);

        return res;
    }
};