class Solution {
public:
    int reverse(int x) {
        int MIN = INT_MIN;
        int MAX = INT_MAX;

        int res = 0;
        int NUM = abs(x);

        while(NUM) {
            int digit = NUM % 10;
            NUM /= 10;

            if(res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10)) {
                return 0;
            }

            if(res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10)) {
                return 0;
            }

            res = (res * 10) + digit;
        }

        return x > 0 ? res: -res;
    }
};
// MAX = -200
// res = 20
// digit = 3
// 20 > 20 || 20 == 20 
// 