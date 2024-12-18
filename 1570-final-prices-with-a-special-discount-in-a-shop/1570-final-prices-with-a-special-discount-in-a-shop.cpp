class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n=p.size();
        vector<int> res;
        for(int i=0;i<n-1;i++){
            int val=p[i];
            int j=i+1;
            while(j<n && p[j]>val){
                j++;
            }
            if(j<n) res.push_back(val-p[j]);
            else    res.push_back(val);
        }
        res.push_back(p.back());
        return res;
    }
};