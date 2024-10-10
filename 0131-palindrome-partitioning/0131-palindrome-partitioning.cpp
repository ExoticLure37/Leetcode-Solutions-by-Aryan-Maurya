class Solution {
public:
    int n;
    vector<vector<string> > res;
    bool isPalin(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l++]!=s[r--])  return false;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> & temp)
    {
        if(idx==n) 
        {
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(isPalin(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.length();
        vector<string>temp;
        solve(0,s,temp);
        return res;
    }
};