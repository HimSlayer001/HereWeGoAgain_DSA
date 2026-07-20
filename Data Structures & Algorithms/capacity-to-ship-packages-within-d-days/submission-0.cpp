class Solution {
public:
    bool check(int mid,vector<int>&weights,int days)
    {
        //now for each mid need to loop over the full array to see if it satisfies the condition;
        int daysUsed=1;
        int currentCap=0;

        for(int i=0; i<weights.size();i++)
        {  
            if(currentCap+weights[i]<=mid)
            {
                currentCap=currentCap+weights[i];
            }
else
{
    currentCap=weights[i];
daysUsed++;
}
        }
        return daysUsed<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        while(lo<hi)
        {//ffffftttttt
            int mid=lo+(hi-lo)/2;
            if(check(mid,weights,days))
            {
                hi=mid;
                

            }
            else
            {
                lo=mid+1;
            }
        }
    return hi;
    }
};