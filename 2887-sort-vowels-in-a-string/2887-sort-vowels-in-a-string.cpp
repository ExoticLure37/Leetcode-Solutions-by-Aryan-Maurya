class Solution {
public:
    string sortVowels(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=s.length();
        vector<char> v;
        string str(n,'#');
        for(int i=0;i<n;i++)
        {   
            char c=s[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            {
                    v.push_back(c);
            }
            else
            {
                str[i]=c;
            }
        }
        int k=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(str[i]=='#') str[i]=v[k++];
        }
        return str;
    }
};