class Solution {
public:
    bool isValid(deque<int> &dq){
        int i=0,n=dq.size();
        int prev=-1;
        for(auto it=dq.begin();it!=dq.end();it++){
            if(prev==-1)    prev=*it;
            else if(*it==prev+1)    prev=*it;
            else    return false;
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        int l=0,r=k;
        deque<int> arr;
        for(int i=0;i<k;i++)    arr.push_back(nums[i]);
        vector<int> res;
        if(isValid(arr))    res.push_back(arr.back());
        else    res.push_back(-1);
        while(r<n)
        {
            arr.pop_front();
            arr.push_back(nums[r]);
            if(isValid(arr))    res.push_back(arr.back());
            else    res.push_back(-1);
            r++;
        }
        return res;
    }
};