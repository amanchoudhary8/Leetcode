class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=a.size(),n=b.size();
        for(int i=0;i<m;i++){
            int j=0;
            while(j<n && a[(i+j)%m]==b[j]) j++;
            if(j==n) return (i+j-1)/m+1;
        }
        return -1;
    }
};