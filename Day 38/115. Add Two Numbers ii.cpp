class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        // Push all values from l1 into s1
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        // Push all values from l2 into s2
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* result = nullptr;
        // Process both stacks until both are empty
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            // Update carry and digit
            carry = sum / 10;
            int digit = sum % 10;
            // Create new node and insert at front
            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;
        }
        return result;
    }
};
//TC O(N+M)
//SC O(N+M)
