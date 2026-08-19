class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        int perimeter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // Skip water
                if (grid[r][c] == 0) {
                    continue;
                }

                // Check all 4 sides of this land cell
                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // If outside grid or adjacent to water,
                    // this side contributes to the perimeter
                    if (nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols ||
                        grid[nr][nc] == 0) {
                        perimeter++;
                    }
                }
            }
        }

        return perimeter;
    }
};