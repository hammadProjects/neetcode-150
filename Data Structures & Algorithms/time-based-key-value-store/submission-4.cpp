class TimeMap {
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(data.count(key) == 0) return "";
        if(data[key].back().first <= timestamp) {
            return data[key].back().second;
        }

        int left = 0, right = data[key].size() - 1;
        string result = "";
        while(left <= right) {
            int mid = ((right - left) / 2) + left;
            if(data[key][mid].first <= timestamp) {
                result = data[key][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

// 10, 20, 30