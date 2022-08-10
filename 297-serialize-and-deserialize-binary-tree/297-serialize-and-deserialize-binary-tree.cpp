/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
     string serialize(TreeNode* root) {
    if(!root) {
     return "NULL,";
    }
    return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<string> q;
    string s;
    for(int i=0;i<data.size();i++)
    {
        if(data[i]==',')
        {
            q.push(s);
            s="";
            continue;
        }
        s+=data[i];
     }
    //if(s.size()!=0)q.push(s);
     return deserialize_helper(q);
}

TreeNode* deserialize_helper(queue<string> &q) {
    string s=q.front();
    q.pop();
    if(s=="NULL")return NULL;
    TreeNode* root=new TreeNode(stoi(s));
    root->left=deserialize_helper(q);
    root->right=deserialize_helper(q);
    return root;
}

//     // Encodes a tree to a single string.
//     void help(TreeNode* root,string &s){
//         if(!root){
//             s+="#,";
//             return;
//         }
//         s+=to_string(root->val)+",";
//         help(root->left,s);
//         help(root->right,s);
//     }
//     string serialize(TreeNode* root) {
//         string ans="";
//         help(root,ans);
//         return ans;
//     }
    
    
    
//      // Decodes your encoded data to tree.
     
//     TreeNode* help2(stringstream &x){
//         string str;
//         getline(x,str,',');
//         if(str=="#")
//             return NULL;
        
//         TreeNode* root=new TreeNode(stoi(str));
//         root->left=help2(x);
//         root->right=help2(x);
//         return root;
     
//     }
    
    
//     TreeNode* deserialize(string data) {
//         vector<int> v;
//         stringstream x(data);
//         TreeNode* root=help2(x);
//         return root;
        
//     }
};

/*
//bfs method
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return s;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            
            if(!n) s+="#,";
            else s+=(to_string(n->val)+",");
            
            if(n){
                q.push(n->left);
                q.push(n->right);
            }
            
        }
        return s;      
    }
    
    
    
    
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root=0;
        if(data=="") return root;
        
        stringstream x(data);
        string str;
        getline(x,str,',');
        
        root=new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            getline(x,str,',');
            if(str!="#"){
                it->left=new TreeNode(stoi(str));
                q.push(it->left);
            }
            getline(x,str,',');
            if(str!="#"){
                it->right=new TreeNode(stoi(str));
                q.push(it->right);
            }
            
        }
        
        
        
        
        return root;
    }
};
*/

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));