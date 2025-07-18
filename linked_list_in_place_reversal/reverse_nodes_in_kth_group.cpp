#include <iostream>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true){
            //Find the kth node
            ListNode* kth = prevGroupEnd;
            for(int i = 0; i < k && kth; ++i){
                kth = kth->next; 
            }
            if (!kth) break; // not enough nodes

            ListNode* groupStart = prevGroupEnd->next; 
            ListNode* nextGroupStart = kth->next; 

            // Reverse the group
            ListNode* prev = nextGroupStart; 
            ListNode* curr = groupStart; 
            while(curr != nextGroupStart){
                ListNode* temp = curr->next; 
                curr->next = prev; 
                prev = curr; 
                curr = temp; 
            }

            // Connect previous group with reversed group
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }
        return dummy.next;
    }
};