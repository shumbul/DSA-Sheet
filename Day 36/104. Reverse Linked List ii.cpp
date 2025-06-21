class Solution {
    ListNode *curr=NULL;  //hold leftptr->next
    ListNode *prev=NULL; //for reversal
     int count=1; //track node positions during traversal
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto leftptr=head;
        auto dummy=new ListNode(); //a placeholder node to easily handle head manipulation especially if left == 1
        dummy->next=head;
        prev=dummy; //it will eventually point to the node just before the reversed sublist
        while (count!=left)
        {
            prev=leftptr;
            leftptr=leftptr->next;
            count++;
        }
        auto prev1=leftptr; //will be tail of the reversed sublist
        auto prev2=prev; //node before the reversed sublist i.e. left-1
        prev2->next=helper(leftptr, right); //return the new head of the reversed sublist
        prev1->next=curr; //prev1 is now the end of the reversed portion, so we connect it to the rest of the list (which curr points to)
        return dummy->next;
    }
    ListNode* helper(ListNode *leftptr, int right)
    {
        while (count!=right+1)
        {
            curr = leftptr->next; //Save the next node temporarily
            leftptr->next = prev; //Reverse the pointer: make current node point to the previous node
            prev = leftptr; //Move prev one step forward
            leftptr = curr; //Move leftptr to the next node (which we had saved as curr earlier)
            count++;                      
        }
        return prev;
    }
};
