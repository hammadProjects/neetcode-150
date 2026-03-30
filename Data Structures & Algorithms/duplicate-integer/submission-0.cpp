class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for(auto num : nums) {
            if(seen.find(num) != seen.end()) {
                return true;
            }
            seen[num]++;
        }
        return false;
    }
};