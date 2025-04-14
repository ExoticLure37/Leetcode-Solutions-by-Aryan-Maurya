class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();

        vector<int> res(n,0);

        sort(potions.begin(),potions.end());
        int k=0;

        for(auto num : spells){
            int l=0,r=potions.size()-1;
            int idx=potions.size();
            while(l<=r){
                int m=l+(r-l)/2;

                if(((long long)potions[m]*(long long)num*1ll) >= success){
                    idx=m;
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }

            res[k++]=(potions.size()-idx);
        }

        return res;
    }
};