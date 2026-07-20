class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();//i will go with max heap;
        priority_queue<int>pq;
        
        for(int i=0; i<n; ++i)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();

            if(first==second)
            {
                continue;
            }

            else{
                pq.push(abs(first-second));
            }
        }
   if(pq.size()==1)
   return pq.top();
   else
   return 0;
    }
    //insertion take logn for each node by doing it for n nodes we are going nlogn 
    //for accessing top element it is O(1)
    //for extracting or poping two elements it take O(logn)also 
    //so max
};
