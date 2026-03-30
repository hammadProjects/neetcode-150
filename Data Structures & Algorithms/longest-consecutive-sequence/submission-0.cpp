class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int cnt = 1, maxCnt = 0;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] || nums[i] == nums[i - 1] + 1) {
                if(nums[i] != nums[i-1]) {
                    cnt++;
                }
            } else {
                cnt = 1;
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};
// 3   3
/*
2
3
4
4
5
10
20
*/