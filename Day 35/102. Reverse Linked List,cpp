class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || head->next == nullptr)
            return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* nextNode = curr->next; // store next node
            curr->next = prev; // reverse current's pointer
            prev = curr; // move prev to current
            curr = nextNode; // move to next node
        }
        return prev;  // prev will be the new head
        //prev is always set to the current that just got reversed. At the end, curr == nullptr, and prev points to the last processed node, which is now the first node of the reversed list
    }
};
