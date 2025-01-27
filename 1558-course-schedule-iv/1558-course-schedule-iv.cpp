class Solution {
public:
    map<int,vector<int> > adj;
    bool DFS(int node,vector<int>& vis,int target){
        if(node==target)    return true;

        vis[node]=1;
        bool fl=false;
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                fl|=DFS(ngbr,vis,target);
            }
        }

        return fl;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for(auto pre : prerequisites){
            int u = pre[0];
            int v = pre[1];
            if(u!=v) adj[v].push_back(u);
        }

        vector<bool > res; 
        for(auto q : queries){
            int u = q[0];
            int v = q[1];

            if(u==v)    res.push_back(true);
            else{
                vector<int> vis(numCourses,0);
                bool found = false;
                found = DFS(v,vis,u);    //node, target
                res.push_back(found);
            }
        }

        return res;
    }
};