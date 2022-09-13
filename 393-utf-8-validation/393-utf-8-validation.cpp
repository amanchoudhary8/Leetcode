class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        int i=0;
        while(i<n){
            int cnt=0,sbit=8,tmp=data[i];
            while(sbit--){
                if(tmp&1) cnt++;
                else cnt=0;
                tmp=tmp>>1;
            }
            i++;
            //cout<<i<<" "<<cnt<<endl;
            if(cnt==0) continue;
            if(cnt==1) return false;
            if(cnt>4) return false;
            cnt--;
            while(cnt  && i<n){
                cnt--;
                int tmp=data[i++];
                //cout<<cnt<<" "<<tmp<<endl;
                if(!(tmp  & (1<<7)) || (tmp & (1<<6))) return false;
                //cout<<"here"<<endl;
            }
            if(cnt) return false;
        }
        return true;
    }
};