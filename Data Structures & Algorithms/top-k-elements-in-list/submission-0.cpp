class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> p;
        vector<int> res;
        unordered_map<int, int> counts;
        for(int num: nums) {
            counts[num]++;
        }

        for(auto& it: counts) {
            p.push_back({it.second, it.first});
        }     

        sort(p.rbegin(), p.rend());

        for(int i = 0; i < k; i++) {
            res.push_back(p[i].second);
        }

        return res;
    }
};
/*
1: 1
2: 2
3: 3
*/

/*
7: 2
*/

// [(2, 7)]