class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int m=matrix.size();
     int n=matrix[0].size();
        bool found=false;
     int low=0;
     int hi=m*n-1;
     while(low<=hi)
     {
int mid=(low+hi)/2;
int row1=mid/n;
int col1=mid%n;
if(target>matrix[row1][col1])
{   
    low=mid+1;
}
else if(target<matrix[row1][col1])
{
    hi=mid-1;
}
else
{
    return true;
}

     }
return false;
    }
};
