class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int fb=-1,la=-1;
        int n=s.length();
        stack<char> st;
        int sna=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                    sna++;
                }
            }
        }
        return sna;
        // if(fb==-1)
        // {
        //     return 0;
        // }
        // int ans=0;
        // for(int i=fb+1;i<n;i++)
        // {
        //     if(s[i]=='a')
        //     {   
        //         // s[i]='c';
        //         ans++;
        //     }
        // }
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(s[i]=='a')  
        //     {
        //         la=i;
        //         break;
        //     } 
        // }
        // int cnt=0;
        // if(la==-1)
        // {
        //     return 0;
        // }
        // for(int i=la-1;i>=0;i--)
        // {
        //     if(s[i]=='b')
        //     {
        //         cnt++;
        //     }
        // }
        // ans = min(ans,cnt);
        // return ans;
    }
};