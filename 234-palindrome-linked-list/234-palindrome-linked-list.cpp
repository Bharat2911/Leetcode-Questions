/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverse(ListNode *head)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode * next;

            while (curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    bool isPalindrome(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = reverse(slow);

        while (head != NULL and head2 != NULL) 
        {
            if(head->val==head2->val)
            {
                head=head->next;
                head2=head2->next;
            }
            else
            {
                return false;
                break;
            }
        }
        return true;
    }
};