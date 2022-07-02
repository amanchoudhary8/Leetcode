class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int m=1000000007;
        hc.push_back(0);
        hc.push_back(h);
        
        vc.push_back(0);
        vc.push_back(w);
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int diff1=0,diff2=0;
        for(int i=1;i<vc.size();i++){
            diff1=max(diff1,vc[i]-vc[i-1]);
        }
        
        for(int i=1;i<hc.size();i++){
            diff2=max(diff2,hc[i]-hc[i-1]);
        }
        return (1LL* (diff1%m)*(diff2%m))%m;
    }
};