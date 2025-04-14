class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n=p.size();
        int m=t.size();
        
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());


        int res=0;
        int i=0,j=0;

        while(i<n && j<m){
            if(p[i]<=t[j]){
                res++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return res;
    }
};