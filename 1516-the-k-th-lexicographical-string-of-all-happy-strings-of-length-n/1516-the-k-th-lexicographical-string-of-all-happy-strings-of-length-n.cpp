class Solution {
public:
    priority_queue<string,vector<string>,greater<string> > pq;
    set<string> s;
    void solve(vector<char> &candidate,string p,vector<int> &vis,int len){
        if(p.size()==len){
            if(s.find(p)==s.end()){
                pq.push(p);
                s.insert(p);
            }
            return;
        }
        for(int i=0;i<3;i++){
            if(p.length()==0 || p.back()!=candidate[i]){
                p.push_back(candidate[i]);
                solve(candidate,p,vis,len);
                p.pop_back();
                // solve(candidate,p,vis,len);
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        string p="";
        vector<char> candidate={'a','b','c'};
        vector<int> vis(3,0);
        solve(candidate,p,vis,n);
        if(pq.size()<k) return "";
        k--;
        while(k--){
            pq.pop();
        }

        return pq.top();
    }
};