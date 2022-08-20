class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> v(n,vector<int>(n,0));
        
        for(auto &p:pre)
            v[p[0]][p[1]]=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    v[j][k]=v[j][k] || (v[j][i] && v[i][k]) ;
                }
            }
        }
        
        vector<bool> ans;
        for(auto &x:q){
            ans.emplace_back(v[x[0]][x[1]]);
        }
        return ans;
        
    }
};