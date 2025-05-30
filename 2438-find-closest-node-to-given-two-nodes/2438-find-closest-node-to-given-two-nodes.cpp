class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        auto getDistances = [&](int start) {
            vector<int> dist(n, INT_MAX);
            int d = 0;
            while (start != -1 && dist[start] == INT_MAX) {
                dist[start] = d++;
                start = edges[start];
            }
            return dist;
        };

        vector<int> dist1 = getDistances(node1);
        vector<int> dist2 = getDistances(node2);

        int result = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
