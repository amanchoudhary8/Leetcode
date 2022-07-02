
class Solution {
public:
      
    bool valid(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
        if (colors[node]) {
            return colors[node] == color;
        }
        colors[node] = color;
        for (int neigh : graph[node]) {
            if (!valid(graph, colors, neigh, -color)) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        for (int i = 0; i < n; i++) {
            if (!colors[i] && !valid(graph, colors, i, 1)) {
                return false;
            }
        }
        return true;
    }
    
  
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> v(n+1,vector<int>{});
        for(auto &pr:dislikes){
            v[pr[0]].push_back(pr[1]);
            v[pr[1]].push_back(pr[0]);
        }
        return isBipartite(v);
    }
};