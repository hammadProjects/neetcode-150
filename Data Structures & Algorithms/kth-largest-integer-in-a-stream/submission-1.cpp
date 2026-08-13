struct cmp {
    bool operator() (const int a, const int b) {
        return a > b;
    }
};

class KthLargest {
    int k;
    priority_queue<
        int,
        vector<int>,
        cmp
    > pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > this->k) {
            pq.pop();
        }

        return pq.top();
    }
};