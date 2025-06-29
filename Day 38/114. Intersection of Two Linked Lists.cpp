class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;
        while (headA) {
            seen.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (seen.count(headB)) 
                return headB; // first common node
            headB = headB->next;
        }
        return nullptr; // no intersection
    }
};
//TC O(n+m)
//SC O(n)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *a = headA, *b = headB;
        while (a) 
        {
            lenA++;
            a = a->next;
        }
        while (b) 
        {
            lenB++;
            b = b->next;
        }
        // Reset pointers
        a = headA;
        b = headB;
        // Move longer list's pointer forward
        if (lenA > lenB) 
        {
            for (int i = 0; i < lenA - lenB; i++) 
            {
                a = a->next;
            }
        } 
        else 
        {
            for (int i = 0; i < lenB - lenA; i++) 
            {
                b = b->next;
            }
        }
        // Traverse together
        while (a && b) 
        {
            if (a == b) 
                return a;
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};
//TC O(N+M)
//SC O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (ListNode* a = headA; a; a = a->next) {
            for (ListNode* b = headB; b; b = b->next) {
                if (a == b) 
                    return a;
            }
        }
        return nullptr;
    }
};
//TC O(N*M)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) 
            return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            if (a == nullptr)
                a = headB; // switch to B after finishing A
            else
                a = a->next;
            if (b == nullptr)
                b = headA; // switch to A after finishing B
            else
                b = b->next;
        }
        return a; // either intersection node or nullptr
    }
};
//TC O(N+M)
