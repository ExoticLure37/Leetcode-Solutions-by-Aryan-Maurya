class Solution {
public:
    int findMinDifference(vector<string>& t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> p;
        int chk=720;
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            int hour = stoi(t[i].substr(0,2));
            int min = stoi(t[i].substr(3,2));

            int val = hour*60+min;
            p.push_back(val);
        }
        sort(p.begin(),p.end());
        int l=p.size();
        int ans=INT_MAX;
        // for(auto i:p)   cout << i << " ";
        cout << endl;
        for(int i=0;i+1<l;i++)
        {
            // cout << " p[i]= "<<p[i] << " p[i+1]= "<<p[i+1]<<endl;
            int val = abs(p[i]-p[i+1]);
            ans=min({ans,val,(1440-val)});
            // cout << "ans = "<<ans<<endl;
        }
        ans = min({ans,abs(p[l-1]-p[0]),1440-abs(p[l-1]-p[0])});
        return ans;
        // return 1;
    }
};