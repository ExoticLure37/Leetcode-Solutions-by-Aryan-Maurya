class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if(parent[x]==x)    return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y)
    {
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y)  return;
        if(rank[parent_x]<rank[parent_y])
            parent[parent_x]=parent_y;
        else if(rank[parent_y]<rank[parent_x])
            parent[parent_y]=parent_x;
        else
            parent[parent_x]=parent_y;
            rank[parent_y]++;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)    parent[i]=i;
        for(auto c:edges)
            Union(c[0],c[1]);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int par=find(i);
            mp[par]++;
        }
        long long res=0,rem=n;
        for(auto c:mp){
            res+=(c.second)*(rem-c.second);
            rem-=c.second;
        }
        return res;
    }
};