class Solution {
public:
    // int dp[301][2];
    int n,m;
    // int calc(vector<vector<int>>& matrix){
    //     int cnt=0;
    //     for(auto c:matrix){
    //         cnt+=(accumulate(c.begin(),c.end(),0)==m)||(accumulate(c.begin(),c.end(),0)==0);
    //     }
    //     return cnt;
    // }
    // void flip(int colIdx,vector<vector<int>>& matrix){
    //     for(int i=0;i<n;i++){
    //         matrix[i][colIdx]=!matrix[i][colIdx];
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++)    cout<<matrix[i][j]<<" ";
    //         cout<<endl;
    //     }
    //     cout<<endl;
    //     return;
    // }
    // int solve(int colIdx,vector<vector<int>>& matrix){
    //     if(colIdx==m){
    //         int p=calc(matrix);
    //         return p;
    //     }
    //     if(dp[colIdx]!=-1)  return dp[colIdx];
    //     cout<<"before flip for colIdx="<<colIdx<<" calc="<<calc(matrix)<<endl;
    //     int pick=0,unpick=0;
    //     pick=solve(colIdx+1,matrix);
    //     flip(colIdx,matrix);
    //     unpick=solve(colIdx+1,matrix);
    //     cout<<"after flip for colIdx="<<colIdx<<" calc="<<calc(matrix)<<endl;
    //     // flip(colIdx,matrix);
    //     return dp[colIdx]=max(pick,unpick);
    // }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // memset(dp,-1,sizeof(dp));
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int> > matrix2(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)    matrix2[i][j]=!matrix[i][j];
        }
        int res=0;
        for(int i=0;i<n;i++){
            vector<int> row=matrix[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    vector<int> tmp1=matrix[j];
                    vector<int> tmp2=matrix2[j];
                    if(row==tmp1 || row==tmp2)   cnt++;
                }
            }
            res=max(res,cnt+1);
        }  
        return  res;  
    }
};