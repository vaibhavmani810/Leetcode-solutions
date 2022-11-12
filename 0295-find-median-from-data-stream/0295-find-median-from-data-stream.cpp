class MedianFinder {
public:
    priority_queue<int> firstq;
    priority_queue<int,vector<int>,greater<int>> secondq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(firstq.empty()||firstq.top()>num)firstq.push(num);
        else
            secondq.push(num);
        if(firstq.size()>secondq.size()+1)
        {
            secondq.push(firstq.top());
            firstq.pop();
        }
        else if(firstq.size()+1<secondq.size())
        {
            firstq.push(secondq.top());
            secondq.pop();
        }
    }
    
    double findMedian() {
        if(firstq.size()==secondq.size())
        {
            return firstq.empty()?0:((firstq.top()+secondq.top())/2.0);
        }
        else
            return firstq.size()>secondq.size()?(double)firstq.top():(double)secondq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */