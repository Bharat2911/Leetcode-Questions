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
    void reorderList(ListNode* head) {
           ListNode *slow = head, *fast = head->next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *head2 = slow -> next;
        slow->next = NULL;

        ListNode *curr = head2, *prev = NULL, *nxt = NULL;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode *head1 = head;
        head2 = prev;

        while (head1 && head2) {
            ListNode* temp1 = head1->next;
            head1->next = head2;
            head1 = temp1;
            ListNode* temp2 = head2->next;
            head2->next = head1;
            head2 = temp2;
        }
    
    }
};