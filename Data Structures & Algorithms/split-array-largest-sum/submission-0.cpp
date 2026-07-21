class Solution {

private:
bool check(int mid,vector<int>&nums, int k)
{
    int currentSum=0;
int newK=1;

for(int i=0; i<nums.size();i++)
{//i need to check that k limit is obliged

//also i need to check that 

if(currentSum+nums[i]<=mid )
{
    currentSum+=nums[i];

}

else
{
    currentSum=nums[i];
    newK++;
    //here i am adding till i am not crossing the mid
}

}
return newK<=k;
}

public:
    int splitArray(vector<int>& nums, int k) {
    int size1=nums.size();
    int lo=*max_element(nums.begin(),nums.end());
    int hi=accumulate(nums.begin(),nums.end(),0);

    while(lo<hi)

{
    int mid=lo+(hi-lo)/2;
    if(check(mid,nums,k))
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