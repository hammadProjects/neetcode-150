class Solution {
public:
    struct cmp {
        bool operator() (const int a, const int b) {
            return b > a;
        }
    };

    // a is worse or not?
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<
            int,
            vector<int>,
            cmp
        > pq;

        for(int stone: stones)
            pq.push(stone);

        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            if(a == b) continue;
            pq.push(abs(a - b));
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};