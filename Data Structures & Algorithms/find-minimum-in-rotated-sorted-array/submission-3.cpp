class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mini = INT_MAX;

        while(l <= r) {
            int mid = (r - l)/2 + l;
            if(nums[l] <= nums[mid]) {
                mini = min(mini, nums[l]);
                l = mid + 1;
            } else {
                mini = min(mini, nums[mid]);
                r = mid - 1;
            }
        }

        return mini;
    }
};