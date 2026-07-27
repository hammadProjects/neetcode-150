class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;

            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++, right--;
                    while(left < n && nums[left - 1] == nums[left]) left++;

                    while((right > i && right < n) && nums[right] == nums[right + 1]) right--;

                } else if(sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ans;
    }
};