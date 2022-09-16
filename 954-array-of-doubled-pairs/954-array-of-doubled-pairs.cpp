class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> u;
        for(auto &a:arr) u[a]++;
        vector<int> unq;
        for(auto &[a,b]:u) unq.push_back(a);
        sort(unq.begin(),unq.end(),[&](int &a,int &b){
            return abs(a)<abs(b);
        });
        for(auto &a:unq){
            if(u[1ll*2*a]<u[a]) return false;
            u[1ll*2*a]-=u[a];
        }
        return true;
    }
};