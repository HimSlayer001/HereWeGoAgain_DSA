class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>st;
        vector<int>ans;

        for(int i=n-1; i>=0;--i)
        {
            if(st.empty())
            {
                ans.push_back(0);
            }
            else{
            while(!st.empty() && st.top().first<=temperatures[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top().second);
            }
           
            }
         st.push({temperatures[i],i});
         }
    reverse(ans.begin(),ans.end());
    vector<int>proper(n);
    for(int i=0; i<n;++i)
    {   if(ans[i]!=0)
        proper[i]=ans[i]-i;
    else proper[i]=0;
    }
    
  return proper;  }
};
