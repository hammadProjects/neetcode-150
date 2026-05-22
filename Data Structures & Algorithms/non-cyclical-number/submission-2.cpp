class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> seen;

        while(n) {
            if(n == 1) return true;
            if(seen.count(n)) return false;
            seen[n] = true;
            
            int sum = 0;
            while(n) {
                int last = (n % 10);
                sum += (last * last);
                n /= 10;
            }

            n = sum;
        }

        return false;
    }
};