class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt=1;
        for(long long l=1;l*(l+1)<2*n;l++){
            double a=(1.0*n-(l*(l+1))/2)/(l+1);
            if(a-int(a)==0) cnt++;
        }
        return cnt;
    }
};