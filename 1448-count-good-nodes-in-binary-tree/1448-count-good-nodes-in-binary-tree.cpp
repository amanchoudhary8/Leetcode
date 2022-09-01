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
    int dfs(TreeNode* root,int high){
        if(!root) return 0;
        int ans=0;
        if(root->val>=high) ans++;
        high=max(high,root->val);
        return ans+dfs(root->left,high)+dfs(root->right,high);
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};