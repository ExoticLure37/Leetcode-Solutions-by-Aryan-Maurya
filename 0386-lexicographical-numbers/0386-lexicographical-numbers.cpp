class Solution {
public:
    static bool cmp(string a,string b)
    {
        int len = min(a.length(),b.length());
        for(int i=0;i<len;i++)
        {
            if(a[i]<b[i])  continue;
            else    return false;
        }
        return true;
    }

    vector<int> lexicalOrder(int n) {
        // vector<int> a;
        // int i=1;
        // while(i<=n && a.size()<n)
        // {
        //     a.push_back(i);
        //     int p=i;
        //     int mul=10;
        //     int r=p*mul;
        //     int cnt=10;
        //     while(r<=n && cnt>0)
        //     {
        //         a.push_back(r);
        //         r++;
        //         cnt--;
        //     }
        //     i++;
        // }
        // return a;
        vector<int> ans(n);
        int x=1;
        for(int i=0; i<n; i++){
            ans[i]=x;
            if (x*10>n){
                if (x==n) x/=10;
                x++;
                while(x%10==0) x/=10;
            } 
            else x*=10;          
        }
        return ans;
    }
};