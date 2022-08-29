class Solution {
public:
    int bs(int i,int n,vector<vector<int>>& intervals,int target){
        while(n-i>1){
            int mid=i+(n-i)/2;
            if(intervals[mid][0]>=target) n=mid;
            else i=mid;
        }
        if(n==intervals.size()) return -1;
        return n;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>,int> m;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            m[intervals[i]]=i;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(intervals[i][0]==intervals[i][1]) ans[m[intervals[i]]]=m[intervals[i]];
            else {
                int k=bs(i,intervals.size(),intervals,intervals[i][1]);
                if(k==-1) ans[m[intervals[i]]]=-1;
                else{
                    ans[m[intervals[i]]]=m[intervals[k]];
                }
            }
        }
        return ans;
    }
};