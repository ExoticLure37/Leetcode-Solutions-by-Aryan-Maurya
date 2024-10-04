class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> mp;
        
        for(auto c:nums1)
        {
            mp[c]++;
        }
        for(auto c:nums2)
        {
            if(mp[c]>0) 
            {
                ans.push_back(c);
                mp[c]--;
            }
        }
        return ans;
    }
};