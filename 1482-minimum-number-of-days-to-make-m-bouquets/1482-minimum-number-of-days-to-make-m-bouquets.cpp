class Solution {
public:
   
    bool valid(vector<int>& bl, int m, int k,int mid){
        int b=0,past=0;
        for(int i=0;i<bl.size();i++){
            if(bl[i]<=mid){
                past++;
                if(past==k){
                    b++;
                    past=0;
                    if(b==m) return true;
                }
            }
            else
                past=0;
        }
        return false;
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long tmp=1LL*m*k;
        int n=bloomDay.size();
        if(tmp>n) return -1;
        
        int lo=1,hi=1000000000;
        int ans=INT_MIN;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(valid(bloomDay,m,k,mid)){
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
            
        }
        return ans;
    }
};