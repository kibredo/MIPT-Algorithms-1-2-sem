#include <iostream>
#include <deque>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2, 0), ans(n + 2);
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
    }
    std::deque<int> d;
    d.push_back(-1);
    for(int u = 1; u < n + 1; ++u) {
        while(a[d.back()] >= a[u]) {
            ans[d.back()] = u;
            d.pop_back();
        }
        d.push_back(u);
    }
    for(int i = 1; i <= n;++i) {
      ans[i] -= 1;
    }
    std::vector<int> answer(n + 2, 0);
    for (int tmp = n; tmp >= 1; --tmp) {
      answer[tmp] = answer[ans[tmp]] + 1;
    }
    std::cout << std::endl;
    for(auto el : answer) {
      std::cout << el << " ";
    }
    return 0;
}
