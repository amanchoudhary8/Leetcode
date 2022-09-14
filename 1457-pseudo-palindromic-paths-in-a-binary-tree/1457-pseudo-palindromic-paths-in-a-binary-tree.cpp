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
    int dfs(TreeNode* root,vector<int> &cnt){
        if(!root) return 0;
        cnt[root->val]++;
        if(!root->left && !root->right){
            int even=0,odd=0;
            for(auto &c:cnt){
                if(c==0) continue;
                if(c&1) odd++;
                else even++;
            }
            cnt[root->val]--;
            if(odd>1) return 0;
            return 1;
        }
        int l=dfs(root->left,cnt);
        int r=dfs(root->right,cnt);
        cnt[root->val]--;
        return (l+r);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10,0);
        return dfs(root,cnt);
    }
};