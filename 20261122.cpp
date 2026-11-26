// https://codeforces.com/contest/2289/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
constexpr ll linf = 4e18;
constexpr int mod = 998244353;


template <typename T>
struct Fenwick {
    int n;
    std::vector<T> tr;

    Fenwick(int n) : n(n), tr(n + 1, 0) {}

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x, T v) {
        for (; x <= n; x += lowbit(x)) {
            tr[x] += v;
        }
    }

    T sum(int x) {
        T res = 0;
        for (; x > 0; x -= lowbit(x)) {
            res += tr[x];
        }
        return res;
    }

    T query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};


void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n + 1);

    for(int i = 1; i <= n; i ++) std::cin >> a[i];

    for(int i = 1; i <= n; i ++) a[i] += a[i - 1];
    for(int i = 1; i <= n; i ++) {
        if(a[i] < 0) {
            std::cout << -1 << "\n";
            return;
        }
    }


    std::vector<ll> val(1, 0);
    for(int i = 1; i <= n; i ++) val.push_back(a[i]);

    std::sort(val.begin() + 1, val.end());
    val.erase(std::unique(val.begin() + 1,  val.end()), val.end());

    auto rk = [&](ll x) -> int {
        return std::lower_bound(val.begin() + 1, val.end(), x) - val.begin();
    };

    Fenwick<int> tr(n + 1);
    ll ans = 0;

    for(int i = n; i >= 1; i --) {
        ans += tr.sum(rk(a[i]) - 1);
        tr.add(rk(a[i]), 1);
    }

    std::cout << ans << '\n';
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
