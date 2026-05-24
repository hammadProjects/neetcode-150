class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();
        vector<int> digits(m + n, 0);

        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + digits[i + j + 1];

                digits[i + j + 1] = sum % 10;
                digits[i + j] += sum / 10;
            }
        }

        string res;
        for(int digit: digits) {
            cout << digit << " ";
            if(!(res.empty() && digit == 0)) {
                res.push_back(digit + '0');
            }
        }

        return res;
    }
};