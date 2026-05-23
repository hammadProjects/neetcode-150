class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        double ans = x;
        for(int i = 1; i < abs(n); i++) {
            ans *= x;
        }

        return n > 0 ? ans : 1/ans;
    }
};