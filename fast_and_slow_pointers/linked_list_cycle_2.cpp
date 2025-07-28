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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {  // cycle found
                break;
            }
        }

        // No cycle
        if (!fast || !fast->next) {
            return nullptr;
        }

        // Step 2: Find cycle start
        slow = head; // Reset slow to head
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;  // start of cycle
    }
};