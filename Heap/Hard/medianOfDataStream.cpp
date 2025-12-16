class MedianFinder {
public:
    priority_queue<int> p; //maxheap -> larger of left side
    priority_queue<int, vector<int>, greater<int>> pq; // minheap -> smaller of right side
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        p.push(num);
        pq.push(p.top()); p.pop();
        if(pq.size()>p.size()){
            p.push(pq.top());
            pq.pop();
        }
    }
    
    double findMedian() {
        if(p.size()>pq.size()) return (double)p.top();
        return (p.top()+pq.top())/2.0;
    }
};


// addNum(x) O(log n)
// findMedian() O(1)
// Space Usage O(n)
