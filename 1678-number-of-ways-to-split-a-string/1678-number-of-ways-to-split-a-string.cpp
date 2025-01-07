class Solution {
public:
    int mod=1e9+7;
    int numWays(string s) {
        int noofones=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='1')   noofones++; 
        }
        if(noofones%3>0)    return 0;
        int left=noofones/3;
        if(left==0){
            unsigned long long q=n-2;
            unsigned long long res=(q*(q+1)*1ll)/2;
            return res%mod;
        }
        int idx=0;
        int o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')   o++;
            if(o==left){
                idx=i;
                break;
            }
        }
        unsigned long long z1=1;
        int mid=0;
        for(int i=idx+1;i<n;i++){
            if(s[i]=='0')   z1++;
            else{
                mid=i;
                break;
            }
        }
        int idx2=0;
        o=0;
        for(int i=mid;i<n;i++){
            if(s[i]=='1')   o++;
            if(o==left){
                idx2=i;
                break;
            }
        }
        unsigned long long z2=1;
        for(int i=idx2+1;i<n;i++){
            if(s[i]=='0')   z2++;
            else{
                break;
            }
        }
        long long p=(z1*z2*1ll)%mod;
        return p;
    }
};