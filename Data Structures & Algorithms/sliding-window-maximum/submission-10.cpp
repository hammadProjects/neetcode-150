class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res;
        int i = 0;
        
        while(i < n) {
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            if(i >= k-1) {
                res.push_back(nums[q.front()]);
            }

            if(!q.empty() && q.front() <= i-k+1) {
                q.pop_front();
            }

            i++;
        }

        return res;
    }
};

// Why queue breaks?
// [4 1 3 2]

// 4 1 3

/*now we have to remove from 
the back from 1 but in queue we will only see
4 and 3 is not greater than 4 and in this way 
it will become 4 1 3
Now this time greater is 4 at front that is correct

But if we go next and 4 will have to be popped
and now we have queue as 1 3 2

now 1 is at front that is wrong
That is why we need to start popping from the back
Deque
*/