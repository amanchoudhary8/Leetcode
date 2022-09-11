class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1,0);
        for(auto &booking:bookings){
            ans[booking[0]-1]+=booking[2];
            ans[booking[1]]-=booking[2];
        }
        for(int i=1;i<n;i++) ans[i]+=ans[i-1];
        ans.resize(n);
        return ans;
    }
};