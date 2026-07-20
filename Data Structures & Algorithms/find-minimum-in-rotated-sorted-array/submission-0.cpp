class Solution {
public:
    int findMin(vector<int> &nums) {
        //use the predicate logic concept here 
        //I need first first smallest after getting a larger
        //FFFFFTTTTT
        //once it was decreasing and the other time it is increasing 
        //need to do a first 
        //was thinking wrong early, had an array already here of values which is to 
        //be found the problem here is binary search on index like simple bs
        //why?go over index and check pr make predicate funtion which minimizes you search space
        //
        int n=nums.size();
        //what would be lo as a condition would be 
        int lo=0;
        int hi=n-1;
        int mid=0;
        while(lo<hi)
        {
            mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi] )
            {
                lo=mid+1;
            }
            else if(nums[mid]<=nums[hi])
            {
hi=mid;
            }
        }
   return nums[hi]; }
};
