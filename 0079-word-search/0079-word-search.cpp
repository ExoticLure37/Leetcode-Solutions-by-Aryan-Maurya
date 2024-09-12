class Solution {
public:
    int n,m;
    int dx[8]={-1,+1,0,0};
    int dy[8]={0,0,-1,+1};
    bool  dfs(pair<int,int> src,vector<vector<char>>& board,vector<vector<int> > &vis,string word,int idx)
    {
        int i=src.first,j=src.second;
        vis[i][j]=1;
        if (idx==word.size())
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size())  
            return false;
        for(int k=0;k<4;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && board[nx][ny]==word[idx])
            {
                if(dfs({nx,ny},board,vis,word,idx+1)==true) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int,int> > index;
        n=board.size();
        m=board[0].size();
        char c = word[0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==c)  index.push_back({i,j});
            }
        }
        if(word.size()==1 && index.size()>0)    return true;
        for(auto i:index)
        {
            vector<vector<int>> vis(n,vector<int>(m,0));
            bool  ans = dfs(i,board,vis,word,1);
            if(ans) return true;
        }
        return false;
    }
};