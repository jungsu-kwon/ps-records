// https://leetcode.com/problems/find-median-from-data-stream

#include <queue>
#include <cmath>

class MedianFinder {
private :
	std::priority_queue<int> maxQueue;
	std::priority_queue<int,std::vector<int>,std::greater<int>> minQueue;
	int getNumElems(){
		return maxQueue.size() + minQueue.size();
	}

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
		if (!getNumElems()){
			maxQueue.push(num);
		}	
		else {
			auto curMedian = findMedian();
			if (num < curMedian){
				maxQueue.push(num);
			}
			else{
				minQueue.push(num);
			}
			if (maxQueue.size() > minQueue.size() + 1){
				auto toPop = maxQueue.top();
				maxQueue.pop();
				minQueue.push(toPop);
			}
			else if (minQueue.size() > maxQueue.size() + 1){
				auto toPop = minQueue.top();
				minQueue.pop();
				maxQueue.push(toPop);
			}

		}

    }
    
    double findMedian() {
		if (getNumElems() % 2 == 0){
			return double(minQueue.top() + maxQueue.top()) /2;
		}
		else if (minQueue.size() > maxQueue.size()){
			return double(minQueue.top());
		}
		else return double(maxQueue.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
