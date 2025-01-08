class Solution {
public:
    bool solve(string a,string b){
        int l=a.length();
        string p=b.substr(0,l);
        string q=b.substr(b.length()-l);
        // cout<<"p="<<p<<" q="<<q<<endl;
        return (a==p && a==q);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int res=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].length()<=words[j].length()){
                    res+=solve(words[i],words[j]);
                }
            }
        }
        return res;
    }
};