class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) 
           return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;
        while (temp && temp->next) {
            ListNode* temp2 = temp->next; //Second node of the pair
            temp->next = temp2->next; //First node points to third
            temp2->next = temp; //Second points to first (swap)
            prev->next = temp2; //Previous node connects to second
            prev = temp; //Move prev to the end of this pair
            temp = temp->next; //Move temp to the next pair's first node
        }
        return dummy->next;
    }
};
