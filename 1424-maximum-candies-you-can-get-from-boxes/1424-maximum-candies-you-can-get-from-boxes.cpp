class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<int> have(n,0);
        vector<int> used(n,0);
        vector<int> can_open(n,0);

        queue<int> q;

        for(auto c:initialBoxes){
            have[c]=1;
            if(status[c]==1){
                can_open[c]=1;
                q.push(c);
            }
        }

        int res=0;
        
        while(q.size()){
            int node=q.front();
            q.pop();

            if(used[node])  continue;

            res+=candies[node];
            used[node]=1;

            for(auto c:keys[node]){
                if(status[c]==0){
                    status[c]=1;
                    if(have[c] && !used[c]) q.push(c);
                }
            }

            for(auto c:containedBoxes[node]){
                have[c]=1;
                if(status[c] && !used[c])   q.push(c);
            }

        }

        return res;
    }
};