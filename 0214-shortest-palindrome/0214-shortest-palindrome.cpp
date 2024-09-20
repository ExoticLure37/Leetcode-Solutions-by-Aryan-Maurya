class Solution {
public:
    string shortestPalindrome(string s) {
        
        // int n=s.length();
        // int i=0,j=0;
        // string p=s;
        // reverse(p.begin(),p.end());
        // while(i<n && j<n)
        // {
        //     int st = j;
        //     while(i<n && j<n && s[i]==p[j])
        //     {
        //         i++,j++;
        //     }
        //     if(j==n)    break;
        //     if(i<n && j<n && s[i]!=p[j])
        //     {
        //         i=0,j=st+1;
        //     }
        // }
        // string rec = s.substr(i,n-i);
        // reverse(rec.begin(),rec.end());
        // // cout << "rec = "<<rec<<endl;
        // string ans = rec;
        // ans+=s;
        // return ans;
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        int n = l.length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && l[i] != l[j]) {
                j = pi[j - 1];
            }
            if (l[i] == l[j]) {
                j++;
            }
            pi[i] = j;
        }

        int k = pi[n - 1];

        string rec = rev_s.substr(0, s.length() - k);
        return rec + s;
    }
};