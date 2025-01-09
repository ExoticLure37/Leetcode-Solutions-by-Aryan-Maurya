class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(auto w:words){
            if(pref==w.substr(0,pref.length())) res++;
        }
        return res;
    }
};