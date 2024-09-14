class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> res(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==mx) res[i+1]=res[i]+1;
        }
        // for(int i=0;i<=n;i++)    cout <<  res[i] << " ";
        // cout<<endl;
        int len = *max_element(res.begin(),res.end());
        return len;
    }
};