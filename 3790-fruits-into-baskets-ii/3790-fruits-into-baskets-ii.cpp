class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();

        int ans=0;
        for(int i=0;i<n;i++){
            int val=fruits[i];
            int fl=0;
            for(int j=0;j<n;j++){
                if(baskets[j]!=-1){
                    if(baskets[j]>=val){
                        baskets[j]=-1;
                        fl=1;
                        break;
                    }
                }
            }
            if(fl==0)   ans++;
        }

        return ans;
    }
};