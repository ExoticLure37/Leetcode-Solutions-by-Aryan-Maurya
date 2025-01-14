class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        sort(intv.begin(),intv.end(),cmp);
        // vector<int> range(1e5+1,0);
        int cnt=0;
        int end=intv[0][1];
        for(int i=1;i<intv.size();i++){
            if(intv[i][0]>=end){
                end=max(end,intv[i][1]);
                cnt++;
            }
        }
        return intv.size()-cnt-1;
    }
};