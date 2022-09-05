/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n=q.size();
            vector<int> tmp;
            while(n--){
                auto x=q.front();q.pop();
                tmp.push_back(x->val);
                for(auto &y:x->children) q.push(y);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};