class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int originalCol = image[sr][sc];
        if(originalCol == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny] == originalCol){
                        image[nx][ny] = color;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return image;
    }
};