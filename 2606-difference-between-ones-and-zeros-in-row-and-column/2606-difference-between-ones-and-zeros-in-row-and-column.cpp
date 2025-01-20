class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++){
            int ones=0;
            for(int j=0;j<m;j++){
                ones+=grid[i][j];
            }
            row[i]=ones;
        }
        
        for(int j=0;j<m;j++){
            int ones=0;
            for(int i=0;i<n;i++){
                ones+=grid[i][j];
            }
            col[j]=ones;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=2*(row[i]+col[j])-n-m;
            }
        }
        return grid;
    }
};