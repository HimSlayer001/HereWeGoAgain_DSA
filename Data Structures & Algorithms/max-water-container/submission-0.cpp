class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
    int l=0;
    int r=n-1;
int water=0;
int maxWater=0;
    while(l<r)
    {
        water=(r-l)*min(height[l],height[r]);
        if(height[l]>height[r])
        r--;
        else
        l++;

        maxWater=max(water,maxWater);
        }
    return maxWater;
    }
};