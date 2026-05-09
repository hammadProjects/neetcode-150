/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> ll;

        while(temp) {
            ll.push_back(temp->val);
            temp = temp->next;
        }

        int n = ll.size();
        int left = 0, right = k - 1;
        while(right <= n - 1) {
            reverse(ll.begin()+left, ll.begin()+right+1);
            left = right + 1;
            right += k;
        }

        temp = head;
        for(int i = 0; i < n; i++) {
            temp->val = ll[i];
            temp = temp->next;
        }

        return head;
    }
};
