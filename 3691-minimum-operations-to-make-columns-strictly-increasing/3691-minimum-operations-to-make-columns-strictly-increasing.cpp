class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                int prev=grid[i-1][j];
                if(grid[i][j]>prev) continue;
                else{
                    res+=(prev+1-grid[i][j]);
                    grid[i][j]=prev+1;    
                }
            }
        }
        return res;
    }
};