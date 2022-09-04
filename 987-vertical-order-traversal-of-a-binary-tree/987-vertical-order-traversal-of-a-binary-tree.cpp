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
    void dfs(TreeNode* root,int col,int row,vector<vector<int>> &v){
        if(!root) return;
        v.push_back({col,row,root->val});
        dfs(root->left,col-1,row+1,v);
        dfs(root->right,col+1,row+1,v);
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> v;
        dfs(root,0,0,v);
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        int n=v.size();
        ans.push_back({v[0][2]});
        for(int i=1;i<n;i++){
            if(v[i][0]==v[i-1][0]){
                ans.back().push_back(v[i][2]);
            }
            else{
                ans.push_back({v[i][2]});
            }
        }
        return ans;
        
    }
    
};















