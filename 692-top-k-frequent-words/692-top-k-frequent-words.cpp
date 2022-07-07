typedef pair<int,string> pi;

class comp{
    public:
    bool operator()(pi p,pi q){
        if(p.first==q.first) return (p.second < q.second);
        
        return (p.first>q.first);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>  ans;
        unordered_map<string,int> u;
        for(string &s:words){
            u[s]++;
        }
        
        priority_queue<pi,vector<pi>,comp> p;
        for(auto &i:u){
            p.push({i.second,i.first});
            if(p.size() >  k) p.pop();
        }
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};