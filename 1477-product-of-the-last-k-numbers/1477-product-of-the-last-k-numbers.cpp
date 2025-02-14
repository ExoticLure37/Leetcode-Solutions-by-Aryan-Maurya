class ProductOfNumbers {
public:
    vector<long long> a;
    ProductOfNumbers() {
        a.clear();
    }
    
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        long long s=1ll;
        for(long long i=a.size()-1;i>=max(0ll,(long long)a.size()-k);i--){
            s*=a[i];
        }
        return s;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */