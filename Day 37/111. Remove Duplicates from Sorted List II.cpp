class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = nullptr; //this will be the head of the new list with only unique nodes
        ListNode* tail = nullptr; //this keeps track of the last node in the new list
        ListNode* curr = head; //the pointer we use to traverse the original list
        while (curr) { //loop through the entire list
            bool isDuplicate = false; //flag to track if the current node is part of duplicates
            //check if the next node has the same value as current
            while (curr->next && curr->val == curr->next->val) {
                isDuplicate = true; //mark as duplicate
                curr = curr->next; // skip the duplicate node
            }
            if (!isDuplicate) 
            {
                //if it's not a duplicate, include it in the new list
                if (!newHead) 
                {
                    newHead = curr; //first unique node becomes the new head
                    tail = curr; //tail also starts here
                } 
                else {
                    tail->next = curr; //append current unique node at the end
                    tail = curr; //move the tail forward
                }
            }
            curr = curr->next; //move to the next node in the original list
        }
        //terminate the new list to avoid cycle or garbage
        if (tail) 
            tail->next = nullptr;
        return newHead; //return the head of the filtered (unique-only) list
    }
};
//TC O(n^2)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) 
            return head;
        //if current node is part of duplicates
        if (head->val == head->next->val) {
            //skip all nodes with the same value
            int duplicateVal = head->val;
            while (head && head->val == duplicateVal) 
            {
                head = head->next;  // Skip this node
            }
            //recursively call on the next unique node
            return deleteDuplicates(head);
        } 
        else {
            //current node is unique, keep it
            //recursively clean the rest of the list
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
//TC O(n)
//SC O(n)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //dummy node points before the original head — helps handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; //points to the last node before the duplicate block
        ListNode* curr = head; //used to scan through the list
        while (curr) 
        {
            //check if current node starts a duplicate sequence
            if (curr->next && curr->val == curr->next->val) 
            {
                int dupVal = curr->val; //store the duplicate value
                //skip all nodes with the same value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                //link previous node to the node after duplicates
                prev->next = curr;
            } 
            else {
                //no duplicate: move both prev and curr one step forward
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;  //return the updated list, skipping dummy
    }
};
//TC O(N)

