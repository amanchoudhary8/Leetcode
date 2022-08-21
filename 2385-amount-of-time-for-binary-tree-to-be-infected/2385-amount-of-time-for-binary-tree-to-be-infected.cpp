/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> par;//node-parent mapping
    unordered_set<TreeNode*> v;//seen or not
    
    
    //doing mapping
    void dfs(TreeNode* root, TreeNode* parent){
        if(!root) return;
        
        par[root]=parent;
        dfs(root->left,root);
        dfs(root->right,root);

    }
    
    TreeNode* dfs2(TreeNode* root, int target){
        if(!root) return NULL;
        
        if(root->val==target) return root;
        TreeNode* l=dfs2(root->left,target);
        TreeNode* r=dfs2(root->right,target);
        
        if(!l) return r;
        else return l;
    }
    
    
    int amountOfTime(TreeNode* root, int tar) {
        TreeNode* target=dfs2(root,tar);
       
        dfs(root,NULL);
        
        queue<TreeNode*> q;
        q.push(target);
        v.insert(target);
        
        int dis=0;
        
        
        //bfs k units outwards from target
        while(!q.empty()){
            int s=q.size();
            
            dis++;
            while(s--){
                auto t=q.front();
                q.pop();
                
                if(t->left && v.find(t->left)==v.end()){
                        v.insert(t->left);
                        q.push(t->left);
                    
                }
                if(t->right && v.find(t->right)==v.end()){
                        v.insert(t->right);
                        q.push(t->right);
                    
                }
                if(par[t] && v.find(par[t])==v.end()){
                        v.insert(par[t]);
                        q.push(par[t]);
                }
            }
        }
        
        return --dis;
    }
};