class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        vector<int> first(26,INT_MAX);
        vector<int> second(26,INT_MIN);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            first[idx]=min(first[idx],i);
            second[idx]=max(second[idx],i);
        }
        int res=0;
        for(int ch=0;ch<26;ch++){
            char c=ch+'a';
            // cout<<"for= "<<first[ch]<<" "<<second[ch]<<" : ";
            if(first[ch]!=second[ch] && first[ch]!=INT_MAX && second[ch]!=INT_MIN){
                int start=first[ch];
                int end=second[ch];
                set<char> unique;
                for(int i=start+1;i<end;i++){
                    unique.insert(s[i]);
                }
                // cout<<" uniques="<<unique.size();
                res+=unique.size();
            }
            cout<<endl;
        }
        return res;
    }
};