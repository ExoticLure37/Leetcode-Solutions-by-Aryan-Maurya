class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26,0);
        for(auto c:s)   freq[c-'a']++;

        int mod=1e9+7;

        for(int i=1;i<=t;i++){
            vector<int> tmp(26,0);
            for(int j=0;j<26;j++){
                int f=freq[j];

                if(j==25){
                    tmp[0]=(tmp[0]+f)%mod;
                    tmp[1]=(tmp[1]+f)%mod;                    
                }
                else{
                    tmp[j+1]=(tmp[j+1]+f)%mod;
                }
            }
            freq=move(tmp);
        }

        int res=0;
        for(auto c:freq)    res+=c,res%=mod;
        return res;
    }
};