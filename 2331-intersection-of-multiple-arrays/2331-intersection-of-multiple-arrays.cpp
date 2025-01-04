class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> mp;
        for(auto arr:nums){
            for(auto c:arr) mp[c]++;
        }
        vector<int> ans;
        for(auto c:mp)
        {
            if(c.second==nums.size())   ans.push_back(c.first);
        }
        return ans;
    }
};