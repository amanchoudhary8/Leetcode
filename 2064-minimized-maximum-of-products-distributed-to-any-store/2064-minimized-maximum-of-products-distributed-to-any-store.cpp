class Solution {
public:
    bool valid(vector<int>& q,int mid,int n){
        long long ans=0;
        for(auto &i:q){
            ans+=ceil(1.0*i/mid);
        }
        if(ans>n) return 0;
        return 1;
    }
    
    int minimizedMaximum(int n, vector<int>& q) {
        int low=0,high=*max_element(q.begin(),q.end());
        while(high-low>1){
            int mid=low+(high-low)/2;
            if(valid(q,mid,n)) high=mid;
            else low=mid;
        }
        return high;
    }
};