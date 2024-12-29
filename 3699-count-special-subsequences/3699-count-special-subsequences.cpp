class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        map<double,long long> mp;
        int n=nums.size();
        long long res=0;
        for(int r=4;r<n;r++){
            for(int p=0,q=r-2;p<q-1;p++)    mp[(double)nums[p]/(double)nums[q]]++;
            for(int s=r+2;s<n;s++)  res+=mp[(double)nums[s]/(double)nums[r]];
        }
        return res;
    }
};