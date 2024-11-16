class Solution {
public:
    int partitionString(string str) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        set<char> s;
        int res=1;
        int n=str.length();
        for(int i=0;i<n;i++){
            if(s.count(str[i])==0)   s.insert(str[i]);
            else{
                s.clear();
                res++;
                s.insert(str[i]);
            }
        }
        return res;
    }
};