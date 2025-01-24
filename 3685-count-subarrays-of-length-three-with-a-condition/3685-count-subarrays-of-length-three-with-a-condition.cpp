class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i+2<n;i++){
            if((nums[i]+nums[i+2])*2==nums[i+1])    res++;
        }
        return res;
    }
};