class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            int minH = heights[i];
            for(int j = i; j < n; j++) {
                minH = min(minH, heights[j]);
                int h = minH;
                int w = j - i + 1;

                maxi = max(maxi, h*w);
            }
        }

        return maxi;
    }
};
