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
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        // Middle
        ListNode* head2 = middle(head);

        // Reverse 2nd half
        head2 = reverse(head2);
        
        // Merge lists
        while(head2) {
            ListNode* n1 = head->next;
            ListNode* n2 = head2->next;

            head->next = head2;
            head2->next = n1;

            head = n1;
            head2 = n2;
        }
    }
};
