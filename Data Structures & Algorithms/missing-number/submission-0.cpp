class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // (5 / 2) = 15
        int n = nums.size();
        vector<int> counts(n+1, 0);
        for(int num : nums) {
            counts[num]++;
        }

        for(int count = 0; count <= n; count++) {
            if(counts[count] == 0) return count;
        }
    }
};
