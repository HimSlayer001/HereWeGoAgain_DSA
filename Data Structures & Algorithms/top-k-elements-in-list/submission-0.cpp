class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     int n=nums.size();
     vector<int>res;
     //what i need to do is return top k frequent element

     //need to do in log n time
     //create an unordered map and call while going k times or nlogk
     //sort of by creating k size map
     unordered_map<int,int>mp(k);
    
     for(int i=0; i<n; i++)
     {
        mp[nums[i]]++;
     }
     //or what i can use is 
        //need to use head
        //what is heap 
        //we need to see which property we need for this 
        //min heap removes smallest number from top
        //we can use frequency as a matrix to insert values in heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
        for(auto& entry: mp)
        {//second is the frequency
            heap.push({entry.second,entry.first});
            
                if (heap.size()>k){
                    heap.pop();
                }
            
     

        }

for(int i=0; i<k;i++)
    {
        res.push_back(heap.top().second);
        heap.pop();
    }

   return res; }
};
