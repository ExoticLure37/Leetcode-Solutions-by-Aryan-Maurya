using ll=long long;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1=accumulate(nums1.begin(),nums1.end(),0ll);
        ll s2=accumulate(nums2.begin(),nums2.end(),0ll);

        ll z1=0,z2=0;
        for(auto c : nums1){
            if(c==0)    z1++;
        }
        for(auto c : nums2){
            if(c==0)    z2++;
        }

        if((s1+z1>s2 && z2==0) || (s1<s2+z2 && z1==0))    return -1;

        return max(z1+s1,z2+s2);
    }
};