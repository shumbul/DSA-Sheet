class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          auto dummy=new ListNode(); //to handle edge cases like removing the first node
          dummy->next=head;
        auto dist=remove(head, n); //start removing from the end
        if (dist==n) //if the node to delete is the head
            return head->next; //skip the head and return the new head
        return dummy->next;

    }
    int remove(ListNode* head, int n)
    {
        if (head==NULL)
            return 0;
        int distance=remove(head->next, n);
          if (distance==n) //if the next node is the one to be removed, skip it
            head->next=head->next->next;
        return distance+1; //distance from current node to end
    }
};
