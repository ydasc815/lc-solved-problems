class Solution {
public:
    int ans = 0;
    int numIslands(vector<vector<char>>& g) {
        vector<vector<int>> vis(g.size(), vector<int> (g[0].size(), 0));
        for(int i=0; i<g.size(); i++) {
            for(int j=0; j<g[0].size(); j++) {
                if(g[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    dfs(g, vis, i, j);
                }
            }
        }
        return ans;        
    }
    void dfs(vector<vector<char>>& g, vector<vector<int>>& vis, int i, int j) {
        if(i < 0 || i == g.size() || j < 0 || j == g[0].size() || vis[i][j] == 1 || g[i][j] == '0') return;
        vis[i][j] = 1;
        dfs(g, vis, i+1, j);
        dfs(g, vis, i-1, j);
        dfs(g, vis, i, j+1);
        dfs(g, vis, i, j-1);
    }
};