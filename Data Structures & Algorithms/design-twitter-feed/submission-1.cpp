struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    // unordered_map<int, unordered_map<int, bool>> followers;
    unordered_map<int, unordered_set<int>> followees;
    int time;
public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({tweetId, time});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        cmp
        > minHeap;

        for(auto& t: tweets[userId]) {
            minHeap.push(t);
            if(minHeap.size() > 10) minHeap.pop();
        }

        for(auto& fol: followees[userId]) {
            for(auto& t: tweets[fol]) {
                minHeap.push(t);
                if(minHeap.size() > 10) minHeap.pop();
            }
        }

        vector<int> feed;
        while(!minHeap.empty()) {
            feed.push_back(minHeap.top().first);
            minHeap.pop();
        }

        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        // followers[followeeId][followerId] = true;
        if(followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // followers[followeeId].erase(followerId);
        followees[followerId].erase(followeeId);
    }
};