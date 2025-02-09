class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        int k=n-1;

        map<int,vector<int> > mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p=i-j;
                mp[p].push_back(grid[i][j]);
            }
        }

        for(auto &c:mp){
            sort(c.second.begin(),c.second.end());
            if(c.first>=0)  reverse(c.second.begin(),c.second.end());   
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p=i-j;
                grid[i][j] = mp[p][0];
                mp[p].erase(mp[p].begin());
            }
        }

        return grid;
    }
};