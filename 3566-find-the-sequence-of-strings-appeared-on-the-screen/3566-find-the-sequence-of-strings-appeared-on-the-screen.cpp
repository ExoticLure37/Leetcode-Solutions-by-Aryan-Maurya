class Solution {
public:
    vector<string> stringSequence(string target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<string> a;
        int n=target.length();
        string p;
        int i=0;
        while(p.length()<n && i<n){
            p+='a';
            a.push_back(p);
            cout<<p<<" ";
            for(int j=1;j<26 && p[i]!=target[i];j++){
                p[i]+=1;
                a.push_back(p);
            }
            cout<<endl;
            i++;
        }
        return a;
    }
};