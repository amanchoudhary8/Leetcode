class Solution {
public:
    void help(int n,int cur,int k,vector<int> &ans){
        if(n==0){
            ans.push_back(cur);
            return;
        }
        int last=cur%10;
        if(last+k<10) help(n-1,cur*10+last+k,k,ans);
        if(k!=0 && last-k>=0) help(n-1,cur*10+last-k,k,ans);
        return;
            
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
            help(n-1,i,k,ans);
        return ans;
        
    }
};