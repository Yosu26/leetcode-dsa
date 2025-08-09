#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        // Keep track of the first node at current level
        Node* curr = root;
        
        while (curr) {
            Node* levelStart = curr;  // Start of current level
            Node* temp = nullptr;     // Used to build next level's connections
            Node* nextLevelStart = nullptr;  // First node of next level
            
            // Process current level and build connections for next level
            while (levelStart) {
                // Process left child
                if (levelStart->left) {
                    if (!nextLevelStart) nextLevelStart = levelStart->left;
                    if (temp) temp->next = levelStart->left;
                    temp = levelStart->left;
                }
                
                // Process right child
                if (levelStart->right) {
                    if (!nextLevelStart) nextLevelStart = levelStart->right;
                    if (temp) temp->next = levelStart->right;
                    temp = levelStart->right;
                }
                
                levelStart = levelStart->next;
            }
            
            curr = nextLevelStart;  // Move to next level
        }
        
        return root;
    }
};