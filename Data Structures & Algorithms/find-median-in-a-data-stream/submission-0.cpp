class MedianFinder {
public: 
vector<int>arr;
int num;
    MedianFinder() {
       
        
    }
    
    void addNum(int num) {
      arr.push_back(num); 
      sort(arr.begin(),arr.end());
    }
    //mean->sort this 
    double findMedian() {
        int n=arr.size();
        if(n%2==0)
        {
            return (arr[n/2-1]+arr[n/2])/2.0;
        }
        else
        {
return arr[(n-1)/2];
        }
    }
};
