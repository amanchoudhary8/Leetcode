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

//method 3
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        TreeNode* cur=root;
        
        while(cur){
            if(!cur->left){
                in.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur)
                    prev=prev->right;
                
                if(!prev->right){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    in.push_back(cur->val);
                    cur=cur->right;
                }
                
            }
        }
        return in;
    }
};


/*
class Solution {
public:
      void helper(TreeNode* root,vector<int> &ans){
        if(!root){
            return;
        }
          helper(root->left,ans);
        ans.push_back(root->val);
        
        helper(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};


*/

/*

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> s;
        TreeNode* node=root;
        while(1){
            if(node){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()) break;
                node=s.top();
                s.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};

*/


