class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        int n=nums.size();
        for(auto c:nums)    pq.push(c);
        long long ans=0;
        while(k--)
        {
            long long val=pq.top();
            pq.pop();
            pq.push(ceil(val/2.0));
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return (int)ans;
    }
};