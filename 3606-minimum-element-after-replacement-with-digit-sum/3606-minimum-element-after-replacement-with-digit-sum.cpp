class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=10000;
        for(auto c:nums)
        {
            int v=0;
            while(c)
            {
                v+=c%10;
                c/=10;
            }
            ans=min(ans,v);
        }
        return ans;
    }
};