class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<long long> f(n+1,0);
        for(auto q:shifts){
            int s=q[0];
            int e=q[1];
            int d=q[2];
            if(d==0){
                f[s]-=1;
                f[e+1]+=1;
            }
            else if(d==1){
                f[s]+=1;
                f[e+1]-=1;
            }
        }
        for(int i=1;i<=n;i++)   f[i]+=f[i-1];
        for(int i=0;i<n;i++){
            int k=s[i]-'a';
            k+=f[i]%26+26;
            k%=26;
            s[i]=k+'a';
            // cout<<f[i]<<" ";
        }
        return s;
    }
};