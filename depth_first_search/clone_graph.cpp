#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloned;
        return dfs(node, cloned);
    }
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloned) {
        if (cloned.count(node)) return cloned[node];
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, cloned));
        }
        return copy;
    }
};