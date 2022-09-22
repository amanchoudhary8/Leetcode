class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int arr[52]={};
        for(auto &x:ranges){
            int a=x[0],b=x[1];
            arr[a]++,arr[b+1]--;
        }
        
        for(int i=1;i<51;i++){
            arr[i]+=arr[i-1];
            if(i>=left && i<=right && arr[i]<1) return 0; 
        }
        return 1;
    }
};