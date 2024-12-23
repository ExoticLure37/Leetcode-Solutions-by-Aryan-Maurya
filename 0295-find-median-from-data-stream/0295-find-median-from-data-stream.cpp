class MedianFinder {
public:
    int len=0;
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
    MedianFinder() {
        // cout<<"hello";
    }
    
    void addNum(int num) {
        len++;
        if(left_max_heap.size()==0) left_max_heap.push(num);
        else if(num<left_max_heap.top())    left_max_heap.push(num);
        else    right_min_heap.push(num);

        if(left_max_heap.size()>right_min_heap.size()+1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
        else if(left_max_heap.size()<right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(len%2==0){
            return ((double)left_max_heap.top()+(double)right_min_heap.top())/2.0;
        }
        else{
            return (double)left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */