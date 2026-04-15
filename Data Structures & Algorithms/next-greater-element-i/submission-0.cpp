class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Idx;
        vector<int> res(nums1.size(), -1);
        stack<int> st;

        for(int i = 0; i < nums1.size(); i++) {
            nums1Idx[nums1[i]] = i;
        }

        st.push(nums2[nums2.size() - 1]);
        for(int i = nums2.size() - 2; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(!st.empty() && nums1Idx.count(nums2[i])) {
                res[nums1Idx[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }

        return res;
    }
};

// [4, 3]
// 1