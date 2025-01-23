class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++){
            int r=0;
            for(int j=0;j<m;j++){
                r+=grid[i][j];
            }
            row[i]=r;
        }
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=0;i<n;i++){
                c+=grid[i][j];
            }
            col[j]=c;
        }

        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (col[j]>1 || row[i]>1)){
                    res++;
                }
            }
        }
       
        return res;
        // set<int> s;
        // for(int i=0;i<n;i++){
        //     if(row[i]>0)    s.insert(i);
        // }
        // for(int j=0;j<m;j++){
        //     if(col[j]>0)    s.insert(j);
        // }
        // return s.size();
    }
};