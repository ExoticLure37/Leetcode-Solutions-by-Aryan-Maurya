class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]%k]++;
        }
        map<int,int> mp2;
        for(auto c:mp)
        {
            if(c.first<0)   
            {
                mp2[(c.first+k)%k]+=c.second;
            }
            else
            {
                mp2[c.first]+=c.second;
            }
        }
        mp.clear();
        for(auto c:mp2)
        {
            cout << c.first << " "<<c.second<<endl;
        }
        cout << endl<<endl;
        if(k==2)
        {
            if(mp2[1]&1)    return false;
        }
        for(auto c:mp2)
        {
            // cout << c.first << " " <<c.second<<endl;
            if(c.first==0)  continue;
            if(c.first == k-c.first && c.second&1)  return false;
            if(c.second!=mp2[k-c.first]) return false;
        }
        // cout << (-4)%3<<endl;
        return true;
    }
};