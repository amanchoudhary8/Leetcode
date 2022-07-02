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
    
    Node* dfs(Node* node,vector<Node*> &vis){
        if(vis[node->val]!=NULL){
           return vis[node->val];
        }
        
        Node* n=new Node(node->val);
        vis[node->val]=n;
        
        vector<Node*> child=node->neighbors;
        for(auto &ch:child)
                n->neighbors.push_back(dfs(ch,vis));
        
        return n;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> vis(101,NULL);
        return dfs(node,vis);
    }
};









































