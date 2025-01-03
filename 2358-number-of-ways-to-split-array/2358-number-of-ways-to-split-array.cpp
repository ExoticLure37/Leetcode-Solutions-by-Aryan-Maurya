class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        long long left=0;
        int res=0;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            sum-=nums[i];
            if(left>=sum)   res++;
        }
        return res;
    }
};