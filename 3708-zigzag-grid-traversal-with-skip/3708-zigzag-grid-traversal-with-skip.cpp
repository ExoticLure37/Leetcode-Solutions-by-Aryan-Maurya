class Solution {
public:
    int n,m;
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        n=grid.size();
        m=grid[0].size();
        int l2r=1;
        int t=1;
        for(int i=0;i<n;i++){
            if(l2r){
                for(int j=0;j<m;j++){
                    if(t)   res.push_back(grid[i][j]);
                    t=!t;
                }
            }
            else{
                for(int j=m-1;j>=0;j--){
                    if(t)   res.push_back(grid[i][j]);
                    t=!t;
                }
            }
            l2r=!l2r;
        } 
        return res;
    }
};