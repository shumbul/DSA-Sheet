class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto odd=head;
        auto even=head->next;
        auto temp=even; //stores the head of even-positioned nodes
        while (even && even->next && odd->next)
        { //reconnect nodes and move ahead
            odd->next=odd->next->next;
            even->next=even->next->next;
            even=even->next;
            odd=odd->next;
        }
        odd->next=temp; //connect the last odd node to the head of the even group
        return head;
    }
};
//TC O(N)
//SC O(1)
