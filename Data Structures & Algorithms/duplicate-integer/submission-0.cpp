class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>yoo;
        for(int i=0; i<n;++i)
        {
            if(yoo.count(nums[i])==1)
            {
                return true;
            }
            else
            {
            yoo.insert(nums[i]);
            }
        }
    return false; }
};