class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() + nums2.size();
        vector<int> nums(m);
        merge(nums1, nums2, nums);
        int mid = m / 2;
        if(m % 2 == 0) {
            return double((nums[mid] + nums[mid - 1]) / 2.0);
        }

        return nums[mid];
    }

private:
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& nums) {
        int idx = 0;
        int n1 = 0, n2 = 0;

        while(n1 < nums1.size() && n2 < nums2.size()) {
            if(nums1[n1] < nums2[n2]) {
                nums[idx++] = nums1[n1++];
            } else {
                nums[idx++] = nums2[n2++];
            }
        }

        while(n1 < nums1.size()) {
            nums[idx++] = nums1[n1++];
        }

        while(n2 < nums2.size()) {
            nums[idx++] = nums2[n2++];
        }
    }
};