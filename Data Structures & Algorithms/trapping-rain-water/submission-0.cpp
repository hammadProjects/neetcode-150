class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftG(n);
        vector<int> rightG(n);
        int res;

        int maxi = INT_MIN;
        for(int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, height[i]);
            rightG[i] = maxi;
        }

        maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, height[i]);
            leftG[i] = maxi;
        }

        for(int i = 0; i < n; i++) {
            res += min(leftG[i], rightG[i]) - height[i];
        }


        return res;
    }
};

// 0 1 2 3 4 5 6 7 8 9
// 0 2 0 3 1 0 1 3 2 1
//       l     r

// if the distance is 1 then move right
// if left is zero both will move by one
// if right is zero then move right
// now what i have thought is, it will count from 1 and move left at right and right at +1
// that is wrong meaning i have need to have the maximum at right meaning i should not skip this part because i have a 3 height on the right of r

// min(l, r) + (internal space)
// 2*(r - l - 1) - (space that is free meaning the internal stone)

// internal space:
// l+1 < r
// 2 < 3