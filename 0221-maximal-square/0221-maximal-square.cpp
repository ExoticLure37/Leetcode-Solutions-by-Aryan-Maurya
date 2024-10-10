class Solution {
public:
    int n,m;
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int> > f(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!i || !j || matrix[i][j]=='0')
                {
                    f[i][j]=matrix[i][j]-'0';
                }
                else{
                    f[i][j]=min({f[i-1][j-1],f[i-1][j],f[i][j-1]})+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,f[i][j]);
                // cout<<f[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans*ans;
    }
};