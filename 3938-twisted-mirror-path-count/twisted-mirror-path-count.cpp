class Solution {
public:
    static const int MOD = 1000000007;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<long long,long long>> dp(n + 1, {0, 0});

        dp[1] = {1, 1};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {
                    dp[c + 1] = {
                        dp[c + 1].second, // DOWN -> RIGHT
                        dp[c].first       // RIGHT -> DOWN
                    };
                } else {
                    long long ways =
                        (dp[c + 1].second + dp[c].first) % MOD;

                    dp[c + 1] = {ways, ways};
                }
            }
        }

        return (int)dp[n].first;
    }
};