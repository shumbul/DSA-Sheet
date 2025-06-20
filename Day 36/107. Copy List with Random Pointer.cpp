class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        auto dummy=new Node(0); //to ease list construction
        auto head2=dummy; //to keep track of the start of new list
        auto temp=head; //to traverse original list
        while (temp!=nullptr)
        {
            auto dummy1=new Node(temp->val);
            dummy->next=dummy1; //append new node to the result list
            temp=temp->next;
            dummy=dummy->next;
        }
        head2=head2->next; //skip dummy node to get actual head of new list
        temp=head;
        auto temp2=head; //to locate the node in copied list that corresponds to random
        auto temp3=head2; //to assign random pointers to nodes in the copied list (parallel to temp)
        while (temp!=nullptr)
        {
          int count=-1;
            while (temp->random )
            {
                count++;
                if (temp->random->val==temp2->val)
                    break;
                temp2=temp2->next;
            }
            if (temp->random && temp->random->val==temp2->val)
            {
                //assign random, reset temp2 to start for next search, move forward in both original and copied list
                temp3->random=temp2;
                temp2=head2;
            }
            temp=temp->next;
            temp3=temp3->next;
        }
        return head2;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto temp = head; //to iterate over the original list
        unordered_map<Node*, Node*> mp; //maps each original node to its copied node
        while (temp != nullptr) {
            auto copy = new Node(temp->val);
            mp[temp] = copy; //original->copy
            temp=temp->next;

        }
        temp = head;
        while (temp != nullptr) {
            mp[temp]->random = mp[temp->random]; //assign random of copy
            mp[temp]->next=mp[temp->next]; //assign next of copy
            temp = temp->next;
        }
        return mp[head]; //copied head
    }
};
