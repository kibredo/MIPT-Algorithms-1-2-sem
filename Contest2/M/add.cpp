#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    int x[n];
    for(int i = 0; i < n;++i)
    {
        cin >> x[i];
    }
    std::vector<int> res(0);
    deque <int> d;
    for (int i = 0; i < n; ++i) {
        if (i >= k && d.front() == i - k)
        {
            d.pop_front();
        }
        while (d.size() && x[d.back()] >= x[i])
        {
            d.pop_back();
        }
        d.push_back(i);
        if (i >= k - 1)
        {
            res.push_back(d.front());
        }
    }
    for(int i = 0; i < n - k + 1;++i)
    {
        cout << x[res[i]] << endl;
    }
    return 0;
}
