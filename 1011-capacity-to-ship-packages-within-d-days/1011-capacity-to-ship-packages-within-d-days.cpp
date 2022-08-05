class Solution {
public:
    bool valid(vector<int>& w,int mid,int days){
        int ans=0,i=0,n=w.size();
        while(i<n){
            if(w[i]>mid) return false;
            int tmp=mid;
            while(i<n && w[i]<=tmp) {
                tmp-=w[i];
                i++;
            }
            ans++;
            if(ans>days) return 0;
        }
        return 1;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=25000000;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(valid(weights,mid,days)) r=mid;
            else l=mid;
        }
        return r;
    }
};