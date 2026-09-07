class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            vector<int> interval(2);
            if(merged.back()[1] >= intervals[i][0]) {
                interval[0] = merged.back()[0];
                interval[1] = max(merged.back()[1], intervals[i][1]);
                merged.pop_back();
            } else {
                interval = intervals[i];
            }

            merged.push_back(interval);
        }

        return merged;    
    }
};