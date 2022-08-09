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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        TreeNode* root=new TreeNode();
        int x=0,y=0;
        TreeNode *l1=NULL,*l2=NULL,*r1=NULL,*r2=NULL;
        if(root1){
            x=root1->val;
            l1=root1->left,r1=root1->right;
        }
        if(root2){
            y=root2->val;
            l2=root2->left,r2=root2->right;
        }
        root->val=(x+y);
        root->left=mergeTrees(l1,l2);
        root->right=mergeTrees(r1,r2);
        return root;
    }
};