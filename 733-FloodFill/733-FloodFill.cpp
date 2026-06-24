// Last updated: 6/24/2026, 1:40:32 PM
1class Solution {
2public:
3    
4    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor) {
5        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val) {
6            return; 
7        }
8        image[i][j] = newColor;
9        dfs(image,i-1,j,val,newColor);
10        dfs(image,i+1,j,val,newColor);
11        dfs(image,i,j-1,val,newColor);
12        dfs(image,i,j+1,val,newColor);
13    }
14    
15    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
16        int val = image[sr][sc];
17        dfs(image,sr,sc,val,newColor);
18        return image;
19    }
20};
21