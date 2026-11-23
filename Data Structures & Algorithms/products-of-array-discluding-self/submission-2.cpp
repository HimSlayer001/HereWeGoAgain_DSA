class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>map1;
        vector<int>ans(n,1);
        vector<int>lef(n,1);
        vector<int>rig(n,1);
        for(int i=1; i<n;i++)
        {
lef[i]=nums[i-1]*lef[i-1];
        }

        for(int i=n-2;i>=0;i--)
        {
rig[i]=nums[i+1]*rig[i+1];
        }
    for(int i=0; i<n;i++)
    {
        ans[i]=lef[i]*rig[i];
    }
    return ans;}
};
