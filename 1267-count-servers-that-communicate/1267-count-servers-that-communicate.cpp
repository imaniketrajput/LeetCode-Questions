class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int communicatingServers = 0;
        vector<int> colServerCount(size(grid[0]), 0); // Servers count in each column
        vector<int> akelaServerCol(size(grid), -1);   // Last server position in each row

        // First pass to count servers in each row and column
        for (int row = 0; row < size(grid); ++row) {
            int serverCountInCurrentRow = 0;
            for (int col = 0; col < size(grid[0]); ++col) {
                if (grid[row][col]) {
                    serverCountInCurrentRow++;          // Count servers in the current row
                    colServerCount[col]++;             // Increment column server count
                    akelaServerCol[row] = col;         // Update last server in this row
                }
            }

            // If more than one server exists in the row, they can all communicate
            if (serverCountInCurrentRow > 1) {
                communicatingServers += serverCountInCurrentRow;
                akelaServerCol[row] = -1; // Mark row as fully handled
            }
        }

        // Second pass to check if isolated servers in rows can communicate via columns
        for (int row = 0; row < size(grid); ++row)
            if (akelaServerCol[row] != -1 && colServerCount[akelaServerCol[row]] > 1) {
                communicatingServers++;
            }

        return communicatingServers;
    }
};