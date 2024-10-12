class Solution {
public:
    int minGroups(vector<vector<int>>& intv) {
        int n=intv.size();
        sort(intv.begin(),intv.end());
        priority_queue<int,vector<int> ,greater<int> > pq;
        pq.push(intv[0][1]);
        int i=1;
        while(i<n)
        {
            if(pq.top() < intv[i][0])
            {
                pq.pop();
                pq.push(intv[i][1]);
            }
            else
            {
                pq.push(intv[i][1]);
            }
            i++;
        } 
        return pq.size();
    }
};