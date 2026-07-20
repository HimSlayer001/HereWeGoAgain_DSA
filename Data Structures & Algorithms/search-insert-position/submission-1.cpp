class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //works on the sortness
        int size1=nums.size();
        int lo=0;
        int hi=size1-1;
        int ans=size1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target)
            {
ans=mid;
hi=mid-1;
            }
      else
      {
        lo=mid+1;
      }  
        }
    return ans;}
};