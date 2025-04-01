class Solution {
public:
    bool hasCycle(int src, vector<set<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        for (auto neigh : adj[src]) {
            if (vis[neigh] == 1) return true;
            if (vis[neigh] == 0 && hasCycle(neigh, adj, vis)) return true;
        }
        vis[src] = 2;
        return false;
    }

    vector<int> topologicalsort(vector<set<int>>& adj, int k) {
        vector<int> order;
        vector<int> inDegree(k+1, 0);
        for (int i = 1; i <= k; i++) {
            for (auto neigh : adj[i]) {
                inDegree[neigh]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (auto neigh : adj[node]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) q.push(neigh);
            }
        }
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<set<int>> adjrow(k+1);
        vector<set<int>> adjcol(k+1);

        for (auto& row : rowConditions) {
            adjrow[row[0]].insert(row[1]);
        }

        vector<int> vis(k+1, 0);
        for (int i = 1; i <= k; i++) {
            if (vis[i] == 0 && hasCycle(i, adjrow, vis)) {
                return {};
            }
        }

        for (auto& col : colConditions) {
            adjcol[col[0]].insert(col[1]);
        }

        fill(vis.begin(), vis.end(), 0);
        for (int i = 1; i <= k; i++) {
            if (vis[i] == 0 && hasCycle(i, adjcol, vis)) {
                return {};
            }
        }

        vector<int> rowOrder = topologicalsort(adjrow, k);
        vector<int> colOrder = topologicalsort(adjcol, k);

        unordered_map<int, int> rowPos, colPos;
        for (int i = 0; i < rowOrder.size(); i++) rowPos[rowOrder[i]] = i;
        for (int i = 0; i < colOrder.size(); i++) colPos[colOrder[i]] = i;

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int num = 1; num <= k; num++) {
            matrix[rowPos[num]][colPos[num]] = num;
        }

        return matrix;
    }
};