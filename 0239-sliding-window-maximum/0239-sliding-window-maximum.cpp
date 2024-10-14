class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        int mx=-100000;
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<k;i++)    pq.push({nums[i],i});
        int r=k;
        res.push_back(pq.top().first);
        while(r<n)
        {
            while(!pq.empty() && pq.top().second<=(r-k))    pq.pop();
            pq.push({nums[r],r});
            res.push_back(pq.top().first);
            r++;
        }
        return res;
    }
};