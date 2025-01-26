class Solution {
public:
    int n;
    vector<int> rank;
    vector<int> parent;

    void dsu_init(int n){
        rank.resize(n);
        parent.resize(n);

        for(int i=0;i<n;i++){
            rank[i]=0;
        }
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    void dsu_union(int x,int y){
        int px=find(x),py=find(y);
        
        if(px==py)  return ;
        
        if(rank[x]>rank[y])   parent[y]=x;
        else if(rank[x]<rank[y])  parent[x]=y;
        else{
            parent[y]=x;
            rank[x]++;
        }
        return;
    }

    int find(int c){
        int px=parent[c];
        if(px==c)   return c;
        return parent[c]=find(parent[c]);
    }

    int sameSet(int x,int y){
        return find(x)==find(y);
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        dsu_init(n); 

        int sz=requests.size();
        vector<bool > ans(sz);

        for(int i=0;i<sz;i++){
            int u = requests[i][0];
            int v = requests[i][1];

            int pu = find(u);
            int pv = find(v);

            bool fl=true;

            for(auto m : restrictions){
                int a = m[0];
                int b = m[1];
                int pa = find(a);
                int pb = find(b);

                if((pu==pa && pv==pb) || (pu==pb && pv==pa)){
                    fl=false;
                    break;
                }
            }

            ans[i]=fl;
            if(fl)  dsu_union(pu,pv);
        }

        return ans;
    }
};