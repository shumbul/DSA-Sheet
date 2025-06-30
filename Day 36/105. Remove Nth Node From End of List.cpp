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
//TC O(N)
//SC O(N)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        // Move fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        // If fast is nullptr, that means we need to delete the head node
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // free the memory of the old head
            return newHead;
        }
        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow is now at the node before the one to be deleted
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // free memory
        return head; // original head is unchanged
    }
};
//TC O(N)
