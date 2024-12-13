class Solution {
public:
    int n;
    map<int,int> mp; 
    int solve(vector<int> &nums,int idx,int sum,map<string,int> &dp){
        if(idx>=n)  return sum;
        string s=to_string(idx)+'#'+to_string(sum);
        if(dp.find(s)!=dp.end())    return dp[s];
        int val=nums[idx];
        int p=0,q=0;
        int fl=0;
        int take=0,nottake=0;
        if(mp[val]>0){
            sum+=val;
            if(mp[val-1]>0){
                p=mp[val-1];
                mp[val-1]=0;
            }
            if(mp[val+1]>0){
                q=mp[val+1];
                mp[val+1]=0;
            }
            mp[val]-=1;
            take=solve(nums,idx+1,sum,dp);
            fl=1;
        }
        if(fl){  
            sum-=val;
            mp[val]++;
            mp[val-1]=p;
            mp[val+1]=q;
        }
        nottake=solve(nums,idx+1,sum,dp);
        return dp[s]=max({take,nottake});
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<long long> dp(10001,0);
        for(auto c:nums)    dp[c]+=c;
        long long take=0,nottake=0;
        for(int i=0;i<10001;i++){
            long long tmp=nottake+dp[i];
            long long ntmp=max(nottake,take);
            take=tmp;
            nottake=ntmp;
        }
        return max(take,nottake);
    }
};