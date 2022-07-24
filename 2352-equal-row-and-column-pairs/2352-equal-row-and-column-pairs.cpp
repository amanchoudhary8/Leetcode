class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> u;
        int n=grid.size();
        for(auto &v:grid){
            u[v]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> tmp;
            for(int r=0;r<n;r++){
                tmp.emplace_back(grid[r][i]);
            }
            if(u.find(tmp)!=u.end()) ans+=u[tmp];
        }
        return ans;
    }
};