class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    bool dfs(int row,int col,int i,vector<vector<char>>& board,vector<vector<bool>> &seen,string &word){
        if(i==word.size())  return true;
        int m=board.size(),n=board[0].size();
        if(row<0 || col<0  || row>=m || col>=n || seen[row][col] || board[row][col]!=word[i]) return false;
        
        seen[row][col]=1;
        for(int d=0;d<4;d++){
            if(dfs(row+dir[d],col+dir[d+1],i+1,board,seen,word)) return true;
        }
        
        seen[row][col]=0;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> seen(m,vector<bool> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,seen,word)) return true;
            }
        }
        return false;
    }
};