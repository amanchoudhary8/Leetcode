class Solution {
public:
    //O(N)
    int findKthPositive(vector<int>& arr, int k) {
        int c=0;
        int last=0;
        for(int &num:arr){
          int tmp=num-last-1;
          if(tmp+c <k){
              c+=tmp;
              last=num;
          }
          else
              break;
       }
        
        return last+(k-c);
    }
};