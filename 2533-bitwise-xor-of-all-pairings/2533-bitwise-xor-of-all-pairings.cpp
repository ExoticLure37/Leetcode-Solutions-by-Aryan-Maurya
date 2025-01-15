class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr1=0;
        int xr2=0;
        for(auto c:nums1)    xr1^=c;
        for(auto c:nums2)    xr2^=c;
        if(nums2.size()%2==0)   xr1=0;
        if(nums1.size()%2==0)   xr2=0;
        return xr1^xr2;
    }
};