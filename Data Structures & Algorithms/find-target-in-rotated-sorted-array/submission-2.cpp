class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (r - l) / 2 + l;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] >= nums[l]) {
                if(target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

// 4,5,6,7,0,1,2
// 0 1 2 3 4 5 6

// 3