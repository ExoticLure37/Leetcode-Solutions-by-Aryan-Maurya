class Solution {
public:
    int n, m;
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};

    bool dfs(pair<int, int> src, vector<vector<char>>& board, vector<vector<int>>& vis, string& word, int idx) {
        int i = src.first, j = src.second;
        if (board[i][j] != word[idx]) return false;
        if (idx == word.size() - 1) return true;
        
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                if (dfs({nx, ny}, board, vis, word, idx + 1)) {
                    return true; 
                }
            }
        }
        
        vis[i][j] = 0; 
        return false;  
    }

    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n = board.size();
        m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (dfs({i, j}, board, vis, word, 0)) {
                        return true; 
                    }
                }
            }
        }
        return false; 
    }
};
