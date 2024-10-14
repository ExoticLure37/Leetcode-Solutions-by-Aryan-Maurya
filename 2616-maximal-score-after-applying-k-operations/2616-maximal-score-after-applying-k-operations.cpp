class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        int n=nums.size();
        for(auto c:nums)    pq.push(c);
        long long ans=0;
        while(k--)
        {
            long long val=pq.top();
            pq.pop();
            ans+=val;
            pq.push(ceil(val/3.0));
        }
        return ans;
    }
};