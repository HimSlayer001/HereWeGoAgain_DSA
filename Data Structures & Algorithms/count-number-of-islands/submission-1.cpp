#define allowed 4

class Solution {
   private:
    static constexpr int dx[4] = {-1, 1, 0, 0};
    static constexpr int dy[4] = {0, 0, 1, -1};

   public:
    void dfs(const vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited) {
        // Mark current cell as visited
        visited[r][c] = true;

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        for (int m = 0; m < allowed; ++m) {
            int nx = r + dx[m];
            int ny = c + dy[m];

            // 1. ALWAYS check boundary limits FIRST
            if (nx < 0 || nx >= totalRows || ny < 0 || ny >= totalCols) {
                continue; // Skip invalid direction
            }

            // 2. Safely check content only after bounds are verified
            if (grid[nx][ny] == '0' || visited[nx][ny]) {
                continue; // Skip water or already visited cells
            }

            // Recurse on valid land cell
            dfs(grid, nx, ny, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int numIslands = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // Pass starting coordinates (i, j), NOT (rows, cols)
                    dfs(grid, i, j, visited);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};