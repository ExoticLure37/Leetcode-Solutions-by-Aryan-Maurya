class Solution {
public:
    vector<bool> prime;
    void seive(int n){
        prime.resize(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                for(int j=2*i;j<=n;j+=i)    prime[j]=false;
            }
        }
    }
    int closest_prime(int prev,int curr){
        for(int i=curr;i>=2;i--){
            if(prime[i]==true && (curr-i)>prev)  return i;
        }
        return 0;
    }
    bool primeSubOperation(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        seive(1000);
        for(int i=0;i<n;i++){
            if(i==0){
                int p=closest_prime(0,nums[i]);
                // cout<<"p="<<p<<endl;
                nums[i]-=p;
            }
            else{
                int p=closest_prime(nums[i-1],nums[i]);
                // cout<<"p="<<p<<endl;
                nums[i]-=p;
            }
        }
        // for(auto c:nums)    cout<<c<<" ";
        for(int i=0;i+1<n;i++){
            if(nums[i]>=nums[i+1])  return false;
        }
        return true;
    }
};