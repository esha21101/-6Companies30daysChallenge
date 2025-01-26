class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int freshOranges = 0, time = 0;

       
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // Process the queue
        while (!q.empty() && freshOranges > 0) {
            int qSize = q.size();
            while (qSize--) {
                auto [x, y] = q.front();
                q.pop();

                
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;

                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOranges--;
                    }
                }
            }
            time++;
        }

        
        return (freshOranges == 0) ? time : -1;
    }
};
