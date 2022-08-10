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
    int help(TreeNode* root,unordered_map<int,int> &u){
        if(!root) return 0;
        int sum=root->val+help(root->left,u)+help(root->right,u);
        u[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> u;
        help(root,u);
        int maxi=INT_MIN;
        
        for(auto &x:u){
            maxi=max(maxi,x.second);
        }
        vector<int> ans;
        for(auto &x:u){
            if(x.second==maxi) ans.push_back(x.first);
        }
        return ans;
    }
};