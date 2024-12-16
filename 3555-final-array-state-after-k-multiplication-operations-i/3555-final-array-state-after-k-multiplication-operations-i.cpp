class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int> &b)
    {
        if(a.first<b.first) return true;
        else if(a.first==b.first)   return a.second==b.second;
        else return false;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int x) {
        
        priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        } 
        while(k--)
        {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            pq.push({val*x,idx});
        }
        // nums.clear();
        vector<int> a(nums.size());
        while(pq.size())
        {
            auto ele = pq.top();
            pq.pop();
            a[ele.second] = ele.first; 
        }
        return a;
    }
};