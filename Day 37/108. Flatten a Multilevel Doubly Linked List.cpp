class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return head;
        helper(head);
        return head;
    }
    Node* helper(Node* head) { //returns the tail node of the flattened sublist
        Node *temp; //will store head->next to keep track of the next node, in case child nodes are inserted
        Node *ans = head; //will keep track of the last processed node
        while (head) {
            if (head->child) {
                auto last = helper(head->child);
                temp = head->next; //store the next node 
                head->next = head->child;
                head->child->prev = head;
                head->child=nullptr; //now merged into the main list
                last->next = temp;
                if (temp) { //if there was a next node after the original head, connect its prev back to the last node of the child list
                    temp->prev = last;
                }
                head = temp;
                ans = last;
            } else {
                ans = head;
                head = head->next;
            }
        }
        return ans;
    }
};
//TC O(N)
//SC O(depth)
