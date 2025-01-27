class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void DSU_init(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    void Union(int x,int y){
        int px=find(x),py=find(y);
        if(px==py)  return;
        else if(rank[x]>rank[y])    parent[y]=x;
        else if(rank[x]<rank[y])    parent[x]=y;
        else{
            parent[x]=y;
            rank[y]++;
        }
    }

    int find(int x){
        if(parent[x]==x)    return parent[x];
        return parent[x]=find(parent[x]);
    }

    bool sameSet(int x,int y){
        return find(x)==find(y);
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if(threshold==0){
            vector<bool > res(queries.size(),true);
            return res;
        }
        
        DSU_init(n+1);
        
        for(int i=1;i<=n;i++){
            for(int j=i+threshold;j<=n;j++){
                if(__gcd(i,j) > threshold){
                    int pu=find(i), pv=find(j);
                    if(pu!=pv){
                        Union(pu,pv);
                    }
                }
            }
        }

        vector<bool >res;
        
        for(auto q : queries){
            int u = q[0];
            int v = q[1];

            bool query = sameSet(u,v);
            res.push_back(query);            
        }

        return res;
    }
};