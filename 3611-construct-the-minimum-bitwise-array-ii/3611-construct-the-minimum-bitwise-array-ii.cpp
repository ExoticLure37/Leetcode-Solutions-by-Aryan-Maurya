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
                int num=nums[i];
                for(int i=0;i<32;i++){
                    if((num&(1<<i)) ==0)
                    {
                        num=num^(1<<(i-1));
                        ans.push_back(num);
                        break;
                    }
                }
            }
        }    
        return ans;
    }
};