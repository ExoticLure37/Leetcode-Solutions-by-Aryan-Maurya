class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i+2<nums.size();i++)
        {
            if(nums[i]) continue;
            else{
                ans++;
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                
            }
        }
        
        // int fl=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                return -1;
            }
        }
        return ans;
    }
};