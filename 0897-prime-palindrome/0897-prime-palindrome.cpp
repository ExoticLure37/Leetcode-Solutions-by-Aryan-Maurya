class Solution {
public:
    const int N = 1e8+5;
        // vector<bool > primes(N,true);
    bool isPrime(int n)
    {
        if(n==0 || n==1)    return 0;
        int p=0,i;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)  return false;
        }
        return true;
    } 
    int primePalindrome(int n) {
        // int i=n;    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n>=1e7 && n<=1e8)    return 100030001;
        while(n<1e7)
        {
            if(isPrime(n))
            {
                string p=to_string(n);
                string q=p;
                reverse(p.begin(),p.end());
                if(p==q)    return n;
            }
            n++;
        }
        return 100030001;
    }
};