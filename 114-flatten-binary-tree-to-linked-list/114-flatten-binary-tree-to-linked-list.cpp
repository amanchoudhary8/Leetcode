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
    TreeNode* prev=0;
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=prev;
        root->left=0;
        prev=root;
    }
};

/*

//method 1
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* node=root;
        while(node){
            if(node->left){
                TreeNode* prev=node->left;
                while(prev->right)
                    prev=prev->right;
                
                prev->right=node->right;
                node->right=node->left;
                node->left=NULL;
            }
            node=node->right;
        }
    }
};
*/