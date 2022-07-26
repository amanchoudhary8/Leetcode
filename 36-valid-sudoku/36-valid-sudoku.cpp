class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9,0),col(9,0),box(9,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int p=board[i][j]-'1';
                int mask=1<<p,b=3*(i/3)+(j/3);
                if(row[i]&mask || col[j]&mask || box[b]&mask) return 0;
                row[i]|=mask;
                col[j]|=mask;
                box[b]|=mask;
            }
        }
        return true;
    }
};