class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode* l3=new ListNode();
        ListNode* curr=l3;
        while (l1!=nullptr || l2!=nullptr || sum!=0)
        {
            
            if(l1 != NULL ) 
            {
                sum += l1->val; 
                l1 = l1->next;
            }
            if(l2 != NULL ) 
            {
                sum += l2->val; 
                l2 = l2->next;
            }
            curr->next=new ListNode(sum%10);
            sum=sum/10;
            curr=curr->next;
        }
        return l3->next;
    }
};
//TC O(n)
