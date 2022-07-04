class Solution {
public:
    
    bool valid(vector<int>& piles, int h,int mid){
        int ch=0;//current hour
        for(int i=0;i<piles.size();i++){
            
            int tmp=(piles[i]+mid-1)/mid;//hr for this pile
            ch+=tmp;
            if(ch>h) return false;
            
         }
        return true;
    }
    
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1,high=1000000000;
        int ans=INT_MAX;
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            if(valid(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else 
                lo=mid+1;
        }
        return ans;
    }
};