typedef pair<int, int> PII;

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        set<vector<PII>> uniqueIslands;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    vector<PII> islandShape;
                    dfs(row, col, grid, islandShape);
                    uniqueIslands.insert(normalize(islandShape));
                }
            }
        }

        return uniqueIslands.size();
    }

private:
    // (4 rotations × 2 reflections)
    vector<PII> normalize(vector<PII>& shape) {
        vector<vector<PII>> allTransformations(8);
        for (const auto& point : shape) {
            int x = point.first;
            int y = point.second;

            // Original and reflections
            allTransformations[0].push_back({x, y});      // Original
            allTransformations[1].push_back({x, -y});     // Reflect along x-axis
            allTransformations[2].push_back({-x, y});     // Reflect along y-axis
            allTransformations[3].push_back({-x, -y});    // Rotate 180°

            // 90° rotation and its reflections
            allTransformations[4].push_back({y, x});      // Rotate 90° counterclockwise
            allTransformations[5].push_back({y, -x});     // Rotate 90° + reflect
            allTransformations[6].push_back({-y, -x});    // Rotate 270° counterclockwise
            allTransformations[7].push_back({-y, x});     // Rotate 270° + reflect
        }

        // Normalize each transformation
        for (auto& transformation : allTransformations) {
            // Sort points to ensure consistent ordering
            sort(transformation.begin(), transformation.end());

            // Translate all points so that the first point is at origin (0, 0)
            int baseX = transformation[0].first;
            int baseY = transformation[0].second;
            for (int i = transformation.size() - 1; i >= 0; --i) {
                transformation[i].first -= baseX;
                transformation[i].second -= baseY;
            }
        }

        // Sort all transformations and return the lexicographically smallest one
        sort(allTransformations.begin(), allTransformations.end());
        return allTransformations[0];
    }

    void dfs(int row, int col, vector<vector<int>>& grid, vector<PII>& shape) {
        shape.push_back({row, col});
        grid[row][col] = 0;
        vector<int> directions = {-1, 0, 1, 0, -1};
        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + directions[dir];
            int newCol = col + directions[dir + 1];
            if (newRow >= 0 && newRow < grid.size() &&
                newCol >= 0 && newCol < grid[0].size() &&
                grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, shape);
            }
        }
    }
};