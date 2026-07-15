class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> majority = {INT_MIN, -1};
        unordered_map<int, int> counts;
        for(int num: nums) {
            counts[num]++;
            if(majority.first < counts[num]) {
                majority.first = counts[num];
                majority.second = num;
            }
        }

        return majority.second;
    }
};