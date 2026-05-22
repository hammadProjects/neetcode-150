class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int one = 1;
        for(int i = n - 1; i >= 0 && one; i--) {
            if(digits[i] < 9) {
                digits[i] += 1;
                one = 0;
            } else {
                digits[i] = 0;
            }
        }

        if(one) {
            // do copying
            vector<int> result(n+1);
            result[0] = 1;
            for(int i = 0; i < n; i++) {
                result[i+1] = digits[i];
            }

            return result;
        }

        return digits;
    }
};