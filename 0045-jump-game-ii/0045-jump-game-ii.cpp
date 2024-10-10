class Solution {
public:
    int n;
    // int solve(int idx,vector<int> &nums)
    // {
    //     if(idx>=n)  return 0;
    //     if(idx==n-1)    return 1;
    //     int skip=solve(idx+1,nums);
    //     int k=nums[idx];
    //     int take=1e9;
    //     for(int i=idx;i<idx+k;i++)
    //     {
    //         take=min(take,solve(i,nums));
    //     }
    //     return min(take,skip);
    // }
    int jump(vector<int>& nums) {
        n=nums.size();
        int j=0,far=0,curr=0;
        if(n==1)    return 0;
        for(int i=0;i<n;i++)
        {
            far=max(far,i+nums[i]);
            if(i==curr) 
            {
                j++;
                curr=far;
                if(curr==n-1)   return j;
            }
        }
        return j;
    }
};