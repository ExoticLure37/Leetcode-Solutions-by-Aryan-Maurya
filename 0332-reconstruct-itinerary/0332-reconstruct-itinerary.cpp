class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> res;

    void DFS(string src) {
        while (!adj[src].empty()) {
            string next = adj[src].top();
            adj[src].pop();
            DFS(next);
        }
        res.push_back(src); // Post-order for Eulerian path
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the adjacency list
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        DFS("JFK");

        reverse(res.begin(), res.end()); // Because we used post-order
        return res;
    }
};
