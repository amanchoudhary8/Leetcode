class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=-1,r=n;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(letters[mid]>target) r=mid;
            else l=mid;
        }
        if(r==n) return letters[0];
        return letters[r];
    }
};