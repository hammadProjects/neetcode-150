class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str: strs) {
            res += to_string(str.size()) + ',';
        }

        res += '#';

        for(string str: strs) {
            res += str;
        }

        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<int> sizes;
        vector<string> strs;
        int i = 0;
        while(s[i] != '#') {
            string curr = "";
            while(s[i] != ',') {
                curr += s[i++];
            }
            sizes.push_back(stoi(curr));
            i++;
        }

        i++; // to skip #
        for(int sz: sizes) {
            string str = s.substr(i, sz);
            strs.push_back(str);
            i += sz;
        }
        
        return strs;
    }
};