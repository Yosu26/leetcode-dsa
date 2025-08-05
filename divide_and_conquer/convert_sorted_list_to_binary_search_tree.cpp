#include <vector>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
private:
    TreeNode* convertToBST(ListNode* start, ListNode* end){
        if(start == end) return nullptr;

        //Find middle using slow and fast pointer technique
        ListNode *slow = start;
        ListNode *fast = start;
        ListNode *prev = nullptr;

        while(fast != end && fast->next != end){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        // Recursively build left and right subtrees
        root->left = convertToBST(start, slow);
        root->right = convertToBST(slow->next, end);

        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head){
        return convertToBST(head, nullptr);
    }
};