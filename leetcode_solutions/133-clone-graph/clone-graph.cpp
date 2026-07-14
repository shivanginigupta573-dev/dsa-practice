/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* ,Node*>mp;
    Node* cloneGraph(Node* node) 
    {
        if(!node)
        return nullptr;
        Node *clone=new Node(node->val);
        if(mp.count(node))
         return mp[node];
         mp[node]=clone;//clone the node
         //then clone the neighbours
         for(auto &nei:node->neighbors)
         {
            clone->neighbors.push_back(cloneGraph(nei));
         }
         return clone;
    }
};