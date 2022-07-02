class Solution {
public:
    
    bool dfs(int node,vector<int> &color,vector<vector<int>>& graph){
        for(auto &i:graph[node]){
            if(color[i]==-1){
                color[i]=1-color[node];
                if(!dfs(i,color,graph)) return false;
            }
            else{
                if(color[node]==color[i]) return false;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(!dfs(i,color,graph)) return false;
            }
        }
        return 1;
    }
};