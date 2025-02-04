class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();

        vector<int> l2r(n);
        vector<int> r2l(n);

        for(int i=0;i<n;i++){
            if(i==0)    l2r[i]=1;
            else{
                if(security[i] <= security[i-1])    l2r[i]=l2r[i-1]+1;
                else    l2r[i]=1;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1)    r2l[i]=1;
            else{
                if(security[i] <= security[i+1])    r2l[i]=r2l[i+1]+1;
                else    r2l[i]=1;
            }
        }

        vector<int> res;

        for(int i=0;i<n;i++){
            if(l2r[i]>time && r2l[i]>time)  res.push_back(i);
        }

        return res;
    }
};