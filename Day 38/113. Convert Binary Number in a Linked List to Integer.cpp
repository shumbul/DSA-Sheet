class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string binary = "";
        while (head) 
        {
            binary += (head->val + '0'); // Append '0' or '1'
            head = head->next;
        }
        int result = 0;
        for (int i = 0; i < binary.size(); i++) 
        {
            result = result * 2 + (binary[i] - '0'); // Convert to decimal
        }
        return result;
    }
};
//TC O(N)
//SC O(N)

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head) {
            result = result * 2 + head->val; // Shift left and add current bit
            head = head->next;
        }
        return result;
    }
};
//TC O(N)
