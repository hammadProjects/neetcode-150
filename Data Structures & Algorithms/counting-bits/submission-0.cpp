class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 32; j++) {
                if((1 << j) & i) {
                    bits[i]++;
                }
            }
        }

        return bits;
    }
};
