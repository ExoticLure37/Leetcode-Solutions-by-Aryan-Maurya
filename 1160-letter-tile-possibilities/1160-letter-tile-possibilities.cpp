class Solution {
public:
    int n;
    set<string> s;
    int res=0;
    void solve(string& tiles,string p,vector<int> &vis){
        s.insert(p);
        for(int i=0;i<tiles.size();i++){
            if(vis[i]==0){
                p.push_back(tiles[i]);
                vis[i]=1;
                solve(tiles,p,vis);
                vis[i]=0;
                p.pop_back();
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        vector<int> vis(tiles.size(),0);
        string p="";
        // n=tiles.size();
        solve(tiles,p,vis);
        return s.size()-1;
    }
};