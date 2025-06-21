#include<iostream>

// /**
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        //Step 1: Count the length and get the tail
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        //Step 2: Make it circular
        tail->next = head;

        //Step 3: Find the new tail: (len - k % len - 1)th node
        k = k % len;
        for(int i = 0; i < len - k - 1; ++i){
            head = head->next;
        }

        //Step 4: Break the circle
        ListNode* newHead = head->next;
        head->next = nullptr;

        return newHead;
    }
};