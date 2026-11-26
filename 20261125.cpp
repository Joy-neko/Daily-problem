// https://codeforces.com/contest/1701/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
constexpr ll linf = 4e18;
constexpr int mod = 998244353;

struct node {
    int id;
    int l, r;
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> b(n + 1);
    for(int i = 1; i <= n; i ++) std::cin >> b[i];

    std::vector<int> ans(n + 1);
    std::vector<node> a(n + 1);

    for(int i = 1; i <= n ;i ++) {
        a[i].l = i / (b[i] + 1) + 1;

        if(b[i] != 0) a[i].r = i / b[i];
        else a[i].r = n;

        a[i].id = i;
    }

    std::sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
        return x.l < y.l;
    });

    int p = 1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for(int i = 1; i <= n; i ++) {
        while(p <= n && a[p].l <= i) {
            pq.push({a[p].r, a[p].id});
            p ++;
        }

        auto [r, id] = pq.top();
        pq.pop();

        ans[id] = i;
    }

    for(int i = 1; i <= n; i ++) std::cout << ans[i] << " ";
    std::cout << "\n";
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
