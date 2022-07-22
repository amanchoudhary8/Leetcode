typedef pair<int,int> pi;
class Solution {
public:
    void merge(vector<pi>& arr,int s, int e,vector<int> &ans){
        int mid=s+(e-s)/2;
        int l=s,r=mid+1;
         
         int j=r;
         for(int i=l;i<=mid;i++){
             while(j<=e && arr[i].first>arr[j].first) j++;
             ans[arr[i].second]+=(j-1)-mid;
         }
         
         
        pi temp[e-s+1];
        int k=0;
        while(l<=mid && r<=e){
            if(arr[l].first<=arr[r].first){
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
        return ;
    }
    
    
void mergesort(vector<pi>& arr,int s,int e,vector<int> &ans){
        if(s>=e) return ;
        int mid=s+(e-s)/2;
        mergesort(arr,s,mid,ans);
        mergesort(arr,mid+1,e,ans);
        
        merge(arr,s,e,ans);
        return;
    }
    

    vector<int> countSmaller(vector<int>& nums) {
        vector<pi> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        
        vector<int> ans(n,0);
        mergesort(v,0,n-1,ans);
        return ans;
    }
};






