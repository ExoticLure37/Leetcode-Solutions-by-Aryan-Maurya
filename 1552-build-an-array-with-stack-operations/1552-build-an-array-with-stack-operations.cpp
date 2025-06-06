class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        int k=1,idx=0;
        while(k<=n && idx<target.size()){
            if(target[idx]!=k){
                res.push_back("Push");
                res.push_back("Pop");
            }
            else{
                res.push_back("Push");
                idx++;
            }
            k++;
        }

        return res;
    }
};