class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> arr;
        arr.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            int tm=startTime[i]-endTime[i-1];
            arr.push_back(tm);
        }
        arr.push_back(eventTime-endTime[endTime.size()-1]);

        int res=0;
        int curr=0;

        k++;
        for(int i=0;i<min(k,(int)arr.size());i++){
            curr+=arr[i];
        }

        res=max(curr,res);

        int i=k;
        while(i<arr.size()){
            res=max(res,curr);
            curr+=arr[i]-arr[i-k];
            i++;
        }

        res=max(res,curr);

        return res;
        

    }
};