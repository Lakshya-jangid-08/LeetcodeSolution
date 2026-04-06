// Last updated: 6/4/2026, 10:42:20 am
/*
what if there is no zeros then ? 

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> d = { -1 , 0 , 1 , 0 , -1 };
        int m = mat.size() , n = mat[0].size();
        queue<pair<int,int>> q;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( mat[i][j] == 0 ) q.push({i,j});
                else mat[i][j] = -1;
            }
        }

        while( !q.empty() ){
            auto [x,y] = q.front(); q.pop();
            for( int i = 0 ; i < 4 ; i++ ){
                int mx = x + d[i] , ny = y + d[i+1];
                if( mx < 0 || mx == m || ny < 0 || ny == n || mat[mx][ny] != -1 ) continue;
                mat[mx][ny] = mat[x][y] + 1;
                q.push({mx,ny});
            }
        }

        return mat;
        
    }
};