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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr = head;
        //skip all leading nodes with value == val
        while (ptr && ptr->val == val) {
            ListNode* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        head = ptr;  //update head to new valid starting node
        //traverse the rest of the list starting from the current ptr
        while (ptr) {
            if (ptr->next && ptr->next->val == val) {
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};
//TC O(N)
//SC O(1)
