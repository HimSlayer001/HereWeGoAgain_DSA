class Solution {
public:
 int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row=grid.size();
    int col=grid[0].size();

 
    int area=0;

    //i will prefer doing a dfs thorugh looping
    for(int i=0; i<row;++i)
    {
        for(int j=0; j<col;++j)
        {

if(grid[i][j]==1)
            {//now i am in the zone
                area=max(area,dfs(grid,i,j));
            }
        }
    }
    return area;}

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int res=1;
        if(r<0 || c<0 || r>=grid.size()|| c>=grid[0].size()||grid[r][c]==0)
        {
            return 0;
        }
        grid[r][c]=0;
        //such that it not loops back();
        for(int i=0; i<4;i++)
        {
           res+=dfs(grid,r+directions[i][0],c+directions[i][1]);
        }
        return res;
    }
};
