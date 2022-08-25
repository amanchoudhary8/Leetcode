struct TrieNode {
    TrieNode *next[26] = {};
    int count = 0;
};

class Trie {
private:
    TrieNode *root;
public:
    
    Trie(){
        root=new TrieNode();
    }
    
    TrieNode* getRoot(){
        return root;
    }
    
    void insert(string word) {
        auto node = root;
        for (char c : word) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->count++;
    }
};




class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    
    void help(int i,int j,string cur,TrieNode *t,vector<vector<char>>& board,vector<string> &ans){
        int m=board.size(),n=board[0].size();
        if(i<0 || j<0 || i==m || j==n || board[i][j]=='#' || !t->next[board[i][j]-'a']) return;
        char c=board[i][j];
        cur+=c;
        t=t->next[board[i][j]-'a'];
        if(t->count>0){
            ans.push_back(cur);
            t->count--;
        }
        board[i][j]='#';
        for(int d=0;d<4;d++){
            help(i+dir[d],j+dir[d+1],cur,t,board,ans);
        }
        board[i][j]=c;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto &word:words) t.insert(word);
        int m=board.size(),n=board[0].size();
        vector<string> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                help(i,j,"",t.getRoot(),board,ans);
            }
        }
        return ans;
    }
};
















