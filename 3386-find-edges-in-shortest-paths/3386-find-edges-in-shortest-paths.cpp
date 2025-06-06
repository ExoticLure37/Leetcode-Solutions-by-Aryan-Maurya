class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& c : edges) {
            adj[c[0]].emplace_back(c[1], c[2]);
            adj[c[1]].emplace_back(c[0], c[2]);
        }

        auto dijkstra = [&](int start) {
            vector<long long> dist(n, LLONG_MAX);
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            dist[start] = 0;
            pq.emplace(0, start);

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;

                for (auto& [v, w] : adj[u]) {
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            return dist;
        };

        vector<long long> distFromStart = dijkstra(0);
        vector<long long> distFromEnd = dijkstra(n - 1);

        long long target = distFromStart[n - 1];
        vector<bool> res;
        for (auto& c : edges) {
            int u = c[0], v = c[1], w = c[2];
            if ((distFromStart[u] != LLONG_MAX && distFromEnd[v] != LLONG_MAX &&
                 distFromStart[u] + w + distFromEnd[v] == target) ||
                (distFromStart[v] != LLONG_MAX && distFromEnd[u] != LLONG_MAX &&
                 distFromStart[v] + w + distFromEnd[u] == target)) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};
