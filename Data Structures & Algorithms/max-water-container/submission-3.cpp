class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        int low = 0;
        int high = n - 1;
        while(high > low) {
            int w = high - low;
            int h = min(heights[low], heights[high]);
            int area = w * h;
            
            maxi = max(maxi, area);

            if(heights[low] > heights[high]) {
                high--;
            } else {
                low++;
            }
        }

        return maxi;
    }
};
