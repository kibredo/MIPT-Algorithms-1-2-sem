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
    int i = m, j = n;
    std::vector<int> special_points;
    while (i > 0) {
        if (dp[i][j].first == (dp[i - 1][j - 1]).first + abs(points[i] - points[dp[i - 1][j].second])) {
            special_points.push_back(points[j - 1]);
            i--;
        }
        j--;
    }
    std::cout << special_points.size() << std::endl;
    for (int i = 0; i < special_points.size(); i++) {
        std::cout << special_points[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
