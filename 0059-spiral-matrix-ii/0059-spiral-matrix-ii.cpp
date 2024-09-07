class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int> > ans(n,vector<int> (n,0));
        int t=0,l=0,r=n-1,b=n-1;
        int k=1;
        while(t<=b && l<=r)
        {
            for(int i=l;i<=r;i++)
            {
                ans[t][i]=k++;
            }
            t++;
            for(int j=t;j<=b;j++)
            {
                ans[j][r]=k++;
            }
            r--;
            for(int i=r;i>=l;i--)
            {
                ans[b][i]=k++;
            }
            b--;
            for(int i=b;i>=t;i--)
            {
                ans[i][l]=k++;
            }
            l++;
        }
        return ans;
    }
};