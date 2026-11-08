class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> row_count(rows, 0);
        vector<int> col_count(cols, 0);
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    row_count[r]++;
                    col_count[c]++;
                }
            }
        }
        
        int communicating_servers = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    if (row_count[r] > 1 || col_count[c] > 1) {
                        communicating_servers++;
                    }
                }
            }
        }
        
        return communicating_servers;
    }
};