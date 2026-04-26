class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int l = 0, r = k-1;
        while(r < n) {
            int maxi = INT_MIN;
            for(int i = l; i <= r; i++) {
                maxi = max(maxi, nums[i]);
            }

            res.push_back(maxi);
            r++, l++;
        }

        return res;
    }
};
