class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<char,int> mp;
        for(auto ch:nums)   mp[ch]++;
        for(auto term:mp){
            if(term.second&1)  return 0;
        }
        return 1;
    }
};