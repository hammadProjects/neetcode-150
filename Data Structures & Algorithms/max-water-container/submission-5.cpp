class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;

        int l = 0, r = n - 1;
        while(l < r) {
            int h = min(heights[l], heights[r]);
            int w = r - l;
            maxi = max(maxi, h*w);
            
            if(heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return maxi;
    }
};