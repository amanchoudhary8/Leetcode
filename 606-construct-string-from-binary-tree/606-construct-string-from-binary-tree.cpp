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
    string help(TreeNode* root){
        if(!root) return "";
        string s1=help(root->left),s2=help(root->right);
        if(s1=="" && s2=="") return "("+to_string(root->val)+")";
        if(s1!="") return "("+to_string(root->val)+s1+s2+")";
        return "(" + to_string(root->val) + "()"+s2+")";
        
    }
    
    string tree2str(TreeNode* root) {
        if(!root) return "";
        
        string s1=help(root->left),s2=help(root->right);
        if(s1=="" && s2!="") return to_string(root->val)+"()"+s2;
        return to_string(root->val)+s1+s2;
    
    }
};