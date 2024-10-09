class Solution {
public:
vector<int> parent;
vector<int> rank;
    int find(int x)
    {
        if(parent[x]==x)    return x;
        return parent[x]=find(parent[x]);
    }
    int n;
    void Union(int x,int y)
    {
        int px=parent[x];
        int py=parent[y];
        if(px==py)  return ;
        else if(rank[px]<rank[py])  parent[px]=py;
        else if(rank[px]>rank[py])  parent[py]=px;
        else
        {
            parent[px]=py;
            rank[py]++;
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        // Union(edges[0][0],edges[0][1]);
        for(int i=0;i<n;i++)
        {
            int px=find(edges[i][0]),py=find(edges[i][1]);
            if(px==py)  
            {
                return {edges[i][0],edges[i][1]};
            }
            else
                Union(edges[i][0],edges[i][1]);
        }

        return {edges[n-1][0],edges[n-1][1]};
    }
};