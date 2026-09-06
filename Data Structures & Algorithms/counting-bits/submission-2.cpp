class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 32; j++) {
                if((1 << j) & i) {
                    bits[i]++;
                }
            }
        }

        return bits;
    }
};