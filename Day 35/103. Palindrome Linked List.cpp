class Solution {
    ListNode* temp;
    bool ans = true;
public:
    bool isPalindrome(ListNode* head) {
        temp = head;
        helper(head);
        return ans;
    }
    void helper(ListNode* node) {
        if (node == nullptr) 
            return;
        helper(node->next);  // reach the end first
        if (temp->val != node->val) {
            ans = false;
            //node: coming from end to front (right side)
            //temp: moves from front to end (left side)
        }
        temp = temp->next;  // move forward from the beginning as we unwind
    }
};
//TC O(N)
//SC O(N) recursion
