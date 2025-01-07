class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        set<string> res;
        for(int j=0;j<n;j++){
            string word=words[j];
            for(int i=0;i<n;i++){
                string s=words[i];
                if(i!=j && s.find(word)!=string::npos){
                    res.insert(word);
                }
            }
        }
        return vector<string> (res.begin(),res.end());
    }
};