class Solution {
public:
    int n;
    vector<vector<string> > res;
    bool isPalin(int i,int j,string &s){
        if(j<i) return false;

        if(i==j)    return true;

        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,string &s,vector<string > tmp){
        if(idx==n){
            res.push_back(tmp);
            return;
        }

        for(int i=idx;i<n;i++){
            if(isPalin(idx,i,s) && (i-idx+1)>0){
                tmp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,tmp);
                tmp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        n=s.length();
        vector<string> tmp;
        solve(0,s,tmp);
        return res;        
    }
};