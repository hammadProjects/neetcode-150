class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = piles[0];
        int k = INT_MAX;
        for(int i = 1; i < n; i++) {
            r = max(r, piles[i]);
        }

        while(l <= r) {
            int mid = (r - l) / 2 + l;
            int cnt = 0;

            for(int i = 0; i < n; i++) {
                cnt += piles[i] / mid;
                if(piles[i] % mid != 0) cnt++;
                if(cnt > h) break;
            }

            if(cnt <= h) {
                k = min(k, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};