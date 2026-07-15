class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for(char c: s)
            counts[c]++;

        string res;
        priority_queue<pair<int, char>> pq;
        for(auto& cnt: counts) 
            pq.push({cnt.second, cnt.first});

        while(!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            for(int i = 0; i < count; i++)
                res.push_back(ch);
        }

        return res;
    }
};