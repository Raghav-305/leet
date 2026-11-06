class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (auto &customer : accounts) {
            int wealth = 0;

            for (int money : customer) {
                wealth += money;
            }

            ans = max(ans, wealth);
        }

        return ans;
    }
};