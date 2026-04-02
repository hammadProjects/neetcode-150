class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int left = 0, right = k - 1;

        while(right < n) {
            int maxi = INT_MIN;
            for(int i = left; i <= right; i++) {
                maxi = max(maxi, nums[i]);
            }

            res.push_back(maxi);
            right++, left++;
        }

        return res;
    }   
};
