class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0); // Dummy node before head
        dummy->next = head;
        ListNode* prev = dummy; //to keep track of the node before curr
        ListNode* curr = head;
        // Find the first node >= x (partition point)
        while (curr && curr->val < x) {
            prev = curr;
            curr = curr->next;
        }
        // Now curr is the first node >= x
        ListNode* insert_pos = prev; //marks where the next node with value < x should be inserted (always before the >= x region)
        while (curr && curr->next) {
            if (curr->next->val < x) {
                //move curr->next to just after insert_pos
                ListNode* move = curr->next; //detach move from its current position, curr->next skips over move and connects to the next node
                curr->next = move->next;
                move->next = insert_pos->next;
                insert_pos->next = move;
                //move insert_pos forward to the node we just inserted
                insert_pos = insert_pos->next;
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
