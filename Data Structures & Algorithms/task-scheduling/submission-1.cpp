class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k=tasks.size();
 vector<int> count(26, 0);
  int time=0;
        queue<pair<int,int>>q;
        for (char task : tasks) {
            count[task - 'A']++;
        }
        priority_queue<int>pq;
        //to store all alphabet in map
        for(auto cnt: count)
        {
            if(cnt>0){
                pq.push(cnt);
            }
            
        }
        //block for n seconds
       
        while(!pq.empty()||!q.empty())
        {
            time++;
            if(pq.empty())
            {
                time=q.front().second;
            }
            else{
                int cnt=pq.top()-1;
                pq.pop();
                if(cnt>0)
                {
                    q.push({cnt,time+n});
                }

            }
if(!q.empty() && q.front().second==time)
{
    pq.push(q.front().first);
    q.pop();
}        
}
 return time;
    }
};
