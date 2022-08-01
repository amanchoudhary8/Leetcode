class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        
        int m=nums1.size(),n=nums2.size();
        int req=(m+n+1)/2; // number of element that should lie in the first half of merged array
        int l=0,r=m;//l--> min. no. of element taken for 1st half from nums1, m--> max. no. of element taken for 1st half from nums1 ( l and m are no indices)
        
        while(l<=r){
            
            // cut 1 and cut2 denote lengths and not indices
            int cut1=l+(r-l)/2;// no. of elements taken from nums1 for first half 
            int cut2=req-cut1;// no. of elements taken from nums2 for first half
            
            
            int l1=(cut1==0) ? INT_MIN : nums1[cut1-1];// last element of nums1 in 1st half
            int l2=(cut2==0) ? INT_MIN : nums2[cut2-1];// last element of nums2 in first half
            int r1=(cut1==m) ? INT_MAX : nums1[cut1];// first element of nums1 in 2nd half
            int r2=(cut2==n) ? INT_MAX : nums2[cut2];// 1st element of nums2 in 2nd half
            
            if(l1>r2) r=cut1-1;
            else if(l2>r1) l=cut1+1;
            else{
                if((m+n)&1) return max(l1,l2);//last element of 1st half is the ans
                else return (max(l1,l2)+min(r1,r2))/2.0;//last elemnt of 1st half and 1st elemnt of 2nd half
            }
        }
        return 0.0;
        
    }
};