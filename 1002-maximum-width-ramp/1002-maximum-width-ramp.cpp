class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty() || nums[s.top()]>nums[i])
            {
                s.push(i);
            }
        }
        int ans=0;
        int mn=1e5,mx=-1;
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                ans = max(ans, j - s.top());
                s.pop();
            }
        }
        return ans;
    }
};