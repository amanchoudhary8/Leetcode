class Solution {
public:
     int merge(vector<int>& arr,long long s, long long e){
        long long int ans=0;
        long long mid=s+(e-s)/2;
        long long l=s,r=mid+1;
         
         int j=r;
         for(int i=l;i<=mid;i++){
             while(j<=e && arr[i]>2LL*arr[j]) j++;
             ans+=(j-1)-mid;
         }
         
         
        long long temp[e-s+1];
        int k=0;
        while(l<=mid && r<=e){
            if(arr[l]<=arr[r]){
                temp[k++]=arr[l++];
            }
            else{
                temp[k++]=arr[r++];
                
            }
        }
        while(l<=mid){
            temp[k++]=arr[l++];
        }
        while(r<=e){
            temp[k++]=arr[r++];
        }
        for(int i=0;i<k;i++){
            arr[s+i]=temp[i];
        }
        return ans;
    }
    
    
int mergesort(vector<int>& arr,long long s, long long e){
        if(s>=e) return 0;
        long long mid=s+(e-s)/2;
        long long lans=mergesort(arr,s,mid);
        long long rans=mergesort(arr,mid+1,e);
        
        long long cur=merge(arr,s,e);
        return (lans+rans+cur);
    }
    
    
   
    
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};



