class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> str1;
        unordered_map<char, int> str2;

        for(auto& chr : s) {
            str1[chr]++;
        }

        for(auto& chr : t) {
            str2[chr]++;
        }

        for(auto& pair : str1) {
            if(str2[pair.first] != pair.second) return false;
        }

        for(auto& pair : str2) {
            if(str1[pair.first] != pair.second) return false;
        }

        return true;
    }
};