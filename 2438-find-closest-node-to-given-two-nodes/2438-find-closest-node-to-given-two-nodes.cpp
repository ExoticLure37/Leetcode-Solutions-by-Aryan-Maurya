class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int> > adj(n);

        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }

        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        function<void(vector<int>&, int)> BFS = [&](vector<int>& dist, int start){
            queue<pair<int,int> > q;
            q.push({start,0});
            dist[start]=0;

            while(q.size()){
                auto front=q.front();
                q.pop();
                int node=front.first;
                int d=front.second;

                for(auto neigh:adj[node]){
                    if(d+1<dist[neigh]){
                        dist[neigh]=d+1;
                        q.push({neigh,dist[neigh]});
                    }
                }
            }
        };

        BFS(dist1,node1);
        BFS(dist2,node2);

        int res=INT_MAX;
        int node=-1;
        for(int i=0;i<n;i++){
            int p=max(dist1[i],dist2[i]);
            if(p<res){
                res=p;
                node=i;
            }
        }

        return node;

    }
};