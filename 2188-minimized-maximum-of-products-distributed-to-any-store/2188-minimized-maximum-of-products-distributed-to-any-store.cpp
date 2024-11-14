class Solution {
public:
    void fast(){
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    }
    int solve(vector<int> &arr,int k,int mid){
        // int t=1;
        // int total=0;
        // for(int i=0;i<quantities.size();i++){
        //     if(total+quantities[i] > k){
        //         total=0;
        //         t++;
        //     }
        //     else{
        //         total+=quantities[i];
        //     }
        //     if(t>n) return false;
        // }
        // return true;
        int stalls = 0;
        int n=arr.size();
        for(int i = 0; i < n; i++)
        {
            stalls += ceil((double) arr[i] / mid);
        }
        
        return stalls <= k;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        fast();
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        // int ans=INT_MAX;
        while(low<high){
            int mid=low+(high-low)/2;
            if(solve(quantities,n,mid)){
                // ans=min(ans,mid);
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};