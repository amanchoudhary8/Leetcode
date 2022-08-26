typedef pair<int,int> pi;
typedef pair<int,pi> ppi;

struct node{
    node* link[2];    
};

class trie{
private:
    node* root;

public:
    trie(){
        root=new node();
    }
    
    void insert(int num){
        node* tmp=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!tmp->link[bit]) tmp->link[bit]=new node();
            tmp=tmp->link[bit];
        }
    }
    
    int maxor(int num){
        node *tmp=root;
        if(!tmp->link[0] && !tmp->link[1]) return -1;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(tmp->link[!bit]){
                maxi=maxi|(1<<i);
                tmp=tmp->link[!bit];
            }
            else
                tmp=tmp->link[bit];
        }
        return maxi;
    }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int m=nums.size(),n=queries.size();
        vector<int> ans(n);
        vector<ppi> v;
        for(int i=0;i<n;i++) v.push_back({queries[i][1],{queries[i][0],i}});
        sort(v.begin(),v.end());
        sort(nums.begin(),nums.end());
        
        trie t;
        int i=0;
        for(int j=0;j<n;j++){
            auto x=v[j];
            while(i<m && nums[i]<=x.first) t.insert(nums[i++]);
            int maxi=t.maxor(x.second.first);
            ans[x.second.second]=maxi;
        }
        return ans;
    }
};



















