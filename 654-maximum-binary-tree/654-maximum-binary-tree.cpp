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
    TreeNode* dfs(vector<int>& nums,int i,int j){
        if(i>j) return NULL;
        auto x=max_element(nums.begin()+i,nums.begin()+j+1);
        int r=x-nums.begin(),val=*x;
        TreeNode* root=new TreeNode(val);
        root->left=dfs(nums,i,r-1);
        root->right=dfs(nums,r+1,j);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};