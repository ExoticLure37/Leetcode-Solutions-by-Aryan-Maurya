class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        long long left=0;
        int idx=-1;
        // if(left==sum)   return -1;
        for(int i=0;i<n;i++){
            sum-=nums[i];
            if(left==sum)   return i;
            left+=nums[i];
        }
        return -1;
    }
};