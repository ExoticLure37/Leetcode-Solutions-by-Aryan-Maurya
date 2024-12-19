class Solution {
public:
    int checkDays(vector<int> & weights,int days,int capacity){
        int d=1;
        int load=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]+load>capacity){
                d++;
                load=0;
            }
            load+=weights[i];
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=INT_MIN;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            mx=max(mx,weights[i]);
            sum+=weights[i];
        }

        int low=mx,high=sum;
        while(low<high){
            int mid=(low+high)/2;
            if(checkDays(weights,days,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};