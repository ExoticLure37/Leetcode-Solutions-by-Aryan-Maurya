class Solution {
public:
    bool chk(string a,string b)
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(s1.length()>s2.length()) return false;
        string p="";
        int i=0;
        for(i=0;i<s1.length();i++)  p+=s2[i];
        if(chk(p,s1))   return true;
        while(i<s2.length())
        {
            // cout<<"entering..."<<endl;
            // cout << "p="<<p<<" s1="<<s1<<endl;
            p=p.substr(1);
            p+=s2[i];
            if(chk(p,s1))   return true;
            i++;
        }
        return false;
    }
};