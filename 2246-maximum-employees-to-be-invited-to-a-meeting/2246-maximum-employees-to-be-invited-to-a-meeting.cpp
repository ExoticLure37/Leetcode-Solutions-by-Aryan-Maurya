class Solution {
public:
    int n;
    int BFS(int start, map<int,vector<int> >& adj,vector<int> &vis2){
        queue<pair<int,int> > q;
        q.push({start,0});
        int mx=0;

        while(q.size()){
            auto [node,dist]=q.front();
            q.pop();

            for(auto ngbr : adj[node]){
                if(!vis2[ngbr]){
                    vis2[ngbr]=1;
                    q.push({ngbr,dist+1});
                    mx=max(mx,dist+1);
                }
            }
        }

        return mx;
    }
    int maximumInvitations(vector<int>& favorite) {
        n=favorite.size();

        map<int,vector<int> > adj;
        
        for(int i=0;i<n;i++){
            int u=i;
            int v=favorite[i];
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        int happyCoupleCount=0;
        int longestCycleLen=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                // find cycle
                map<int,int> mp;
                int currNode=i;
                int currDist=0;

                while(!vis[currNode]){
                    vis[currNode]=1;
                    mp[currNode]=currDist;
                    currDist+=1;
                    int nextNode=favorite[currNode];

                    if(mp.count(nextNode)){

                        int cycleLen=currDist-mp[nextNode];
                        longestCycleLen = max(longestCycleLen,cycleLen);

                        if(cycleLen==2){
                            vector<int> vis2(n,0);
                            vis2[currNode]=1;
                            vis2[nextNode]=1;
                            happyCoupleCount+=2+BFS(currNode,adj,vis2)+BFS(nextNode,adj,vis2);
                        }
                        break;
                    }
                    currNode=nextNode;
                }
            }
        }
        return max(happyCoupleCount,longestCycleLen);
    }
};