class Solution {
public:
    struct cmp {
        bool operator() (const int a, const int b) {
            // If a is worse or not
            // true = yes
            // false = no

            return b > a;
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<
            int,
            vector<int>,
            cmp
        > pq;

        for(int num: nums) pq.push(num);

        for(int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top();
    }
};