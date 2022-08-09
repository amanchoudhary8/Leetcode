class NumArray {
public:
    vector<int> v,pre;
    NumArray(vector<int>& nums) {
        v=nums;
        int n=v.size();
        int s=0;
        for(auto &i:v){
            s+=i;
            pre.emplace_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right]-pre[left]+v[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */