class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.length();
        vector<int> vis(n,0);
        int a=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) vis[i]=1,a++;
            else    mp[guess[i]]++;
        }
        int b=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(mp[secret[i]]>0){
                    mp[secret[i]]--;
                    b++;
                }
            }
        }
        string res="";
        res=to_string(a)+'A'+to_string(b)+'B';
        return res;
    }
};