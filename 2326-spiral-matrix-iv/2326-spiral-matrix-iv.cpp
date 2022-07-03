/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int dir[]={0,1,0,-1,0};
        vector<vector<int>> mat(m,vector<int>(n,-1));
        int d=0;
        
        int i=0,j=0;
        while(1){
            mat[i][j]=head->val;
            
            head=head->next;
            if(!head) break;
            int tmpi=i+dir[d];
            int tmpj=j+dir[d+1];
            if(tmpi<0 || tmpi>=m || tmpj<0 || tmpj>=n || mat[tmpi][tmpj]!=-1)
              d=(d+1)%4;
            
            i=i+dir[d];
            j=j+dir[d+1];
        }
        return mat;
        
    }
};





















