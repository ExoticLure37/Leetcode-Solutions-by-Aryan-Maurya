class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0}); // {cost, x, y}
        
        while (!pq.empty()) {
            int cost = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            
            if (x == n - 1 && y == m - 1) return cost;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    int currCost = (grid[x][y] == i + 1) ? 0 : 1;
                    pq.push({cost + currCost, nx, ny});
                }
            }
        }
        
        return 0;
    }
};
