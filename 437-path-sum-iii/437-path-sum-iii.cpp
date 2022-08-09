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
    
    void dfs(TreeNode* root,unordered_map<long long,int> &u,long long cur, int &target,int &ans){
        if(!root) return;
        cur+=root->val;
        if(u.find(cur-target)!=u.end()) 
            ans+=u[cur-target];
        
        u[cur]++;
        dfs(root->left,u,cur,target,ans);
        dfs(root->right,u,cur,target,ans);
        u[cur]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> u;
        int ans=0;
        u[0]=1;
        dfs(root,u,0,targetSum,ans);
        return ans;
    }
};