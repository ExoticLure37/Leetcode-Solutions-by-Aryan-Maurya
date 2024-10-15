class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)    ans.push_back(-1);
            else {
                int p=0;
                while(p+1<nums[i]){
                    if((p|(p+1))==nums[i]) break;
                    p++;
                }
                ans.push_back(p);
            }
        }    
        return ans;
    }
};