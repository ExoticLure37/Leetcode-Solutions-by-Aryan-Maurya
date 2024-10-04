class Solution {
public:
    int minMoves(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans=0;
        int mn=*min_element(nums.begin(),nums.end());
        // sort(nums.begin(),nums.end());
        set<int>s;
        // for(auto c:nums)    s.insert((mx-));
        for(auto c:nums)   ans+=(c-mn);
        return ans;
    }
};