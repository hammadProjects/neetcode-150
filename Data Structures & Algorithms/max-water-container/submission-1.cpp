class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int w = j - i;
                int h = min(heights[i], heights[j]);

                int area = w * h;
                maxi = max(maxi, area);
            }
        }

        return maxi;
    }
};
