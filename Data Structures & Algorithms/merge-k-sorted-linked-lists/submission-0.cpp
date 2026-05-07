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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];
        for(int i = 1; i < n; i++) {
            ListNode* dummy = new ListNode();
            ListNode* head = dummy;
            ListNode* h1 = lists[0];
            ListNode* h2 = lists[i];

            while(h1 && h2) {
                if(h1->val >= h2->val) {
                    head->next = h2;
                    h2 = h2->next;
                } else {
                    head->next = h1;
                    h1 = h1->next;
                }

                head = head->next;
            }

            if(h1) {
                head->next = h1;
            } else {
                head->next = h2;
            }

            lists[0] = dummy->next;
            delete dummy;
        }
        
        return lists[0];
    }
};

// 1 2 3 
// 2 3 4
// 1