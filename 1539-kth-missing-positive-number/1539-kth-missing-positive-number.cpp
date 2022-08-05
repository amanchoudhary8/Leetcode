class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k) return k;
        int lo=0,hi=arr.size();
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]-mid-1<k) lo=mid;
            else hi=mid; 
        }
        return arr[lo]+(k-(arr[lo]-lo-1));
        
    }
};