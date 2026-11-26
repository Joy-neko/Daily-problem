// https://codeforces.com/contest/1854/problem/A2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
constexpr ll linf = 4e18;
constexpr int mod = 998244353;


void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) std::cin >> a[i];

    std::vector<std::pair<int, int>> res1, res2;

    int mx = -inf, mn = inf, ind1 = -1, ind2 = -1;

    for(int i = 1; i <= n; i ++) {
        if(a[i] > mx) {
            mx = a[i];
            ind1 = i;
        }
        if(a[i] < mn) {
            mn = a[i];
            ind2 = i;
        }
    }

    if(mn >= 0) {
        std::cout << n - 1 << '\n';
        for(int i = 2; i <= n; i ++) std::cout << i << " " << i - 1 << '\n';
        return;
    }

    if(mx <= 0) {
        std::cout << n - 1 << '\n';
        for(int i = n - 1; i >= 1; i --) std::cout << i << " " << i + 1 << '\n';
        return;
    }

    int x = mx, y = mn;

    while(x < -mn) {
        res1.push_back({ind1, ind1});
        x *= 2;
    }

    while(-y < mx) {
        res2.push_back({ind2, ind2});
        y *= 2;
    }

    for(int i = 1; i <= n; i ++) {
        if(a[i] < 0) {
            res1.push_back({i, ind1});
        }
        else if(a[i] > 0) {
            res2.push_back({i, ind2});
        }
    }

    for(int i = 2; i <= n; i ++) {
        res1.push_back({i, i - 1});
    }

    for(int i = n - 1; i >= 1; i --) {
        res2.push_back({i, i + 1});
    }

    if(res1.size() <= 31) {
        std::cout << res1.size() << "\n";
        for(auto [x, y] : res1) std::cout << x << " " << y << '\n';
    }
    else {
        std::cout << res2.size() << "\n";
        for(auto [x, y] : res2) std::cout << x << " " << y << '\n';
    }
}


int main() { 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while(t --) {
        solve();
    }
}
