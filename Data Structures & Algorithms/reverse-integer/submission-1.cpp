class Solution {
public:
    int reverse(int x) {
        int NUM = abs(x);
        int res = 0;

        while(NUM) {
            if(res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }
            
            res = (res * 10) + NUM % 10;
            NUM /= 10;
        }

        return x < 0 ? -res : res;
    }
};