class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> freq(26,0);
        for(auto w:words2){
            vector<int> tmp(26,0);
            for(auto c:w)   tmp[c-'a']++;
            for(int i=0;i<26;i++)   freq[i]=max(freq[i],tmp[i]);
        }
        for(auto w:words1){
            vector<int> v(26,0);
            for(auto c:w)   v[c-'a']++;
            bool fl=1;
            for(int i=0;i<26;i++){
                if(v[i]<freq[i]){
                    fl=0;
                    break;
                }
            }
            if(fl)  res.push_back(w);
        }

        return res;
    }
};