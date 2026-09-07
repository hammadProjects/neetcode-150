class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        int n = intervals.size();
        merged.push_back(intervals[0]);
        for(int i = 1; i < n; i++) {
            vector<int> interval(2);
            if(merged.back()[1] >= intervals[i][0]) {
                // getting merged
                vector<int> back = merged.back();
                merged.pop_back();
                interval[0] = back[0];
                interval[1] = max(back[1], intervals[i][1]);
            } else {
                // just adding the interval
                interval = intervals[i];
            }
            merged.push_back(interval);
        }

        return merged;
    }
};