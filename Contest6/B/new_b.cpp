#include <iostream>
#include <vector>

#define INF 1e9

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> points(n + 1, 0);
    std::vector<std::vector<std::pair<int, int>>> dp(n + 1, std::vector<std::pair<int, int>>(m + 1, {INF, 0}));
    dp[0][0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        std::cin >> points[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j].first = std::min(dp[i - 1][j - 1].first, dp[i - 1][j].first + abs(points[i] - points[dp[i - 1][j].second]));
            if (dp[i - 1][j - 1].first < dp[i - 1][j].first + abs(points[i] - points[dp[i - 1][j].second])) {
                dp[i][j].second = dp[i - 1][j - 1].second;
            } else {
                dp[i][j].second = i;
            }
        }
    }
    std::cout << dp[n][m].first << std::endl;
    std::cout << std::endl;
    return 0;
}
