struct cmp {
    bool operator() (const int a, const int b) {
        return a > b;
    }
};

class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, cmp> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }

        if(large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
        
        else if(small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == large.size()) {
            return ((small.top() + large.top()) / 2.0);
        } else if(small.size() > large.size()) {
            return small.top();
        } else {
            return large.top();
        }
    }
};