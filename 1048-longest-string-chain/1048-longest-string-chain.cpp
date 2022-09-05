class Solution {
public:
    bool compare(string &a,string &b){
        if(a.size() !=b.size()+1) return 0;
        int fir=a.length(),sec=b.length(),i=0,j=0;
        while(i<fir){
            if(j<sec && a[i]==b[j]) {
                i++;
                j++;
            }
             else i++;   
        }
        return j==sec;
     }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.length()<b.length();
        });
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};