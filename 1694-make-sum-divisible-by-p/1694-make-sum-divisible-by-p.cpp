class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int len=INT_MAX;
        for(int i=0;i<nums.size();i++)
            nums[i]%=p;
        long long target=accumulate(nums.begin(),nums.end(),0ll)%p;
        if(target==0)   return 0;
        if(count(nums.begin(),nums.end(),target)>0) return 1;
        long long sum=0;
        int l=0,r=0;
        map<int,int>mp;
        mp[0]=-1;
        while(r<nums.size())
        {
            sum+=nums[r];
            sum%=p;
            int prefix = (sum-target+p)%p;
            if(mp.find(prefix)!=mp.end())
            {
                int length = r-mp[prefix];
                len=min(len,length);
            }
            mp[sum]=r;
            r++;
        }
        cout <<" len = "<<len<<endl;
        return (len==nums.size() || len==INT_MAX)?-1:len;

    }
};