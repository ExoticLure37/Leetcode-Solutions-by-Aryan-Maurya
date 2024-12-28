class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        map<int,int> mp;
        for(auto c:nums)    mp[c]++;
        int p=1;
        while(mp[p]>0){
            mp[p]=1;
            p<<=1;
        }
        return p;
    }
};