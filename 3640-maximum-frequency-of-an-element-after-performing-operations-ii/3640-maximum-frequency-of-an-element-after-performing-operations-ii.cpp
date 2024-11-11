class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int p) {
        map<long long,int> freq,diff;
        set<long long> s;
        int mx=0;
        for(auto c:nums){
            freq[c]++;
            diff[max(0,c-k)]++;
            diff[c+k+1]--;
            s.insert(max(0,c-k));
            s.insert(c+k+1);
            s.insert(c);
            mx=max(mx,freq[c]);
        } 
        int ans=0;
        int curr=0;
        for(auto i:s){
            curr+=diff[i];
            ans=max(ans,min(curr,freq[i]+p));
        }
        return min(ans,mx+p);
    }
};