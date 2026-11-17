class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map1;
        int res=0;
        for(int num : nums)
        {
            if(!map1[num])
            {
            map1[num]=map1[num-1]+map1[num+1]+1;
            map1[num-map1[num-1]] = map1[num];
            map1[num+map1[num+1]] = map1[num];
            res=max(res, map1[num]);
            }
            
        }



        return res;        
        }
};
