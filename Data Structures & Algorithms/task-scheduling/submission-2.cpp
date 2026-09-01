class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for(char t: tasks)
            counts[t - 'A']++;

        priority_queue<int> pq; // maxHeap by default
        for(int cnt: counts)
            if(cnt > 0)
                pq.push(cnt);

        queue<pair<int, int>> q;
        int time = 0;
        while(!q.empty() || !pq.empty()) {
            time++;
            if(pq.empty()) {
                time = q.front().second;
            } else {
                int cnt = pq.top() - 1;
                pq.pop();

                if(cnt > 0)
                    q.push({cnt, time + n});
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};