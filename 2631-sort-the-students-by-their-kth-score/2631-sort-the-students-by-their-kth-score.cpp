class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n=score.size();

        priority_queue<pair<int,int> > pq;

        for(int i=0;i<n;i++){
            pq.push({score[i][k],i});
        } 

        vector<vector<int> > ans(n);
        int p=0;
        while(!pq.empty()){
            auto [val, idx] = pq.top();
            pq.pop();

            ans[p++]=score[idx];
        }

        return ans;
    }
};